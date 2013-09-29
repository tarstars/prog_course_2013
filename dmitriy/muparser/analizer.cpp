#include "analizer.h"
#include "defines.h"
#include <fstream>
#include <vector>

#include <stdio.h>

int targetindex=0;

#define TARGET_NAME_SIZE 7 /*out000\0*/

struct Target
{
        enum TargetType
        {
            Target_Invalid = 0,
            Target_Numeric = 1,
            Target_Text    = 2,
            Target_Make    = 3,
            Target_Complex = 4
        };

        char name[TARGET_NAME_SIZE];
        TargetType type;
        const char* str;
        int str_size;
        OperationType nextOperation;

        Target(): type(Target_Invalid),str(0),str_size(0),
            nextOperation(Operation_Plus)
        {
            memset(name,0,sizeof(name));
        }

        void makeName()
        {
            sprintf(name, "out%03d", targetindex++);
        }

        bool isValid() const { return (type != Target_Invalid);}
};

bool findTarget(const char* str, int& start, int end, Target& nextTarget)
{
    if(start>=end)
    {
        nextTarget = Target();
        return true;
    }

    if(*(str+start)=='(')
    {
        nextTarget.str = (str+(++start));
        nextTarget.type = Target::Target_Complex;
        nextTarget.makeName();

        int ind = 1;
        while(ind&&(start<end))
        {
            switch(*(str+(start++)))
            {
                case ')':--ind;break;
                case '(':++ind;break;
                default:break;
            }
        }
        if(ind)
        {
            fprintf(stderr,"Invalid expression - unbalanced paranthesis\n");
            return false;
        }
        nextTarget.str_size = (str+start-1)-nextTarget.str;
    }
    else if(mathoperand(*(str+start)))
    {
        fprintf(stderr,"Invalid expression - two math operands one after another\n");
        return false;
    }
    else
    {
        nextTarget.str = (str+(start++));
        nextTarget.makeName();

        while(!mathoperand(*(str+start)) && (start<end)){++start;}
        nextTarget.str_size = (str+start)-nextTarget.str;
        nextTarget.type = numbersonly (nextTarget.str,nextTarget.str_size) ?
                              Target::Target_Numeric : Target::Target_Text;

        if(start==end)
        {
            nextTarget.nextOperation = Operation_Plus;
            return true;
        }
    }

    switch(*(str+start))
    {
        case '+':nextTarget.nextOperation = Operation_Plus;break;
        case '-':nextTarget.nextOperation = Operation_Subtract;break;
        case '*':nextTarget.nextOperation = Operation_Multiply;break;
        case '/':nextTarget.nextOperation = Operation_Divide;break;
        default:/*should never happen*/break;
    }
    ++start;
    return true;
}

/*target1 & target2 must be simple or processed targets*/
Target make_entry(const Target& target1, const Target& target2, std::ostream& os)
{
    if(!target1.isValid () || !target2.isValid ())
    {
        fprintf(stderr,"Algorithm error - requensted make entry on invalid targets\n");
        return Target();
    }

    if((target1.type == Target::Target_Complex)||(target2.type == Target::Target_Complex))
    {
        fprintf(stderr,"Algorithm error - requensted make entry on complex target\n");
        return Target();
    }

    Target output;
    output.type = Target::Target_Make;
    output.makeName ();
    output.str = output.name;
    output.str_size = strlen(output.name);
    output.nextOperation = target2.nextOperation;

    os<<output.name<<": calculator.cpp";
    switch(target1.type)
    {
        case Target::Target_Make: os<<" "<<target1.name;break;
        case Target::Target_Text:
        {
            os<<" ";
            os.write (target1.str,target1.str_size);
            os<<".txt";
            break;
        }
        default:break;
    }
    switch(target2.type)
    {
        case Target::Target_Make: os<<" "<<target2.name;break;
        case Target::Target_Text:
        {
            os<<" ";
            os.write (target2.str,target2.str_size);
            os<<".txt";
            break;
        }
        default:break;
    }

    os<<"\n\tg++ -o "<<output.name<<".exec calculator.cpp -D"<<kOperationDefines[target1.nextOperation]
      <<"\n\t./"<<output.name<<".exec ";

    switch(target1.type)
    {
        case Target::Target_Make:    os<<target1.name<<".txt";break;
        case Target::Target_Numeric:
        case Target::Target_Text:
        {
            os.write (target1.str,target1.str_size);
            if(target1.type==Target::Target_Text) os<<".txt";
            break;
        }
        default:break;
    }
    os<<" ";

    switch(target2.type)
    {
        case Target::Target_Make:    os<<target2.name<<".txt";break;
        case Target::Target_Numeric:
        case Target::Target_Text:
        {
            os.write (target2.str,target2.str_size);
            if(target2.type==Target::Target_Text) os<<".txt";
            break;
        }
        default:break;
    }

    os<<" > "<<output.name<<".txt\n";

    fprintf(stderr,"Target %s & %s makes %s\n", target1.name,target2.name,output.name);
    return output;
}

Target process_plusminus(std::ostream& os,const char* rest, int rest_size,
                         Target& lowPriorityPrev);

Target process(std::ostream& os, const char* str, int str_size, const Target& prevTarget)
{
    fprintf(stderr,"Called process for %.*s (%d bytes)\n", str_size,str,str_size);
    int start=0;
    Target nextTarget = Target();
    if(!findTarget(str,start,str_size,nextTarget))
    {
        fprintf(stderr,"Error looking for new target\n");
        return Target();
    }
    fprintf(stderr, "Next target: %.*s (operation: %s)\n",
            nextTarget.str_size,nextTarget.str,
            &(kOperationStrings[nextTarget.nextOperation].at(0)));

    if(nextTarget.isValid () && (nextTarget.type == Target::Target_Complex))
    {
        fprintf(stderr,"New target %s is complex - processing it\n", nextTarget.name);
        OperationType op_bak = nextTarget.nextOperation;
        nextTarget = process(os,nextTarget.str,nextTarget.str_size,Target());
        nextTarget.nextOperation = op_bak;
        fprintf(stderr,"New complex target processed  - is now %s\n", nextTarget.name);
    }

    if(!nextTarget.isValid()) //end of data or error
    {
        if(prevTarget.isValid()) //that's an error
        {
            fprintf(stderr,"EOD, but got target from previous round - error!\n");
            return Target();
        }
        //ok, just an EOD
        fprintf(stderr,"Next target is invalid - possible EOD\n");
        return Target();
    }

    //nextTarget is valid
    if(prevTarget.isValid ())
    {
        fprintf(stderr, "Got previous target %s\n", prevTarget.name);
        Target prevCorrected = ((prevTarget.type != Target::Target_Complex) ? prevTarget :
                                                       process (os,prevTarget.str,
                                                                prevTarget.str_size,Target()));
        prevCorrected.nextOperation = prevTarget.nextOperation;
        fprintf(stderr,"Corrected previous target %s - it is now %s\n",
                prevTarget.name,prevCorrected.name);

        if(!prevCorrected.isValid ())
        {
            fprintf(stderr,"Cannot process prevTarget\n");
            return Target();
        }

        if(str_size<=start)
        {
            fprintf(stderr,"EOD\n");
            return make_entry (prevCorrected,nextTarget,os);
        }

        if(!operationHighPriority (prevTarget.nextOperation))
        {
            fprintf(stderr,"Algorithm bug - called process with prevTarget & low priority operation\n");
            return Target();
        }
        else
        {
            Target replace = make_entry (prevCorrected,nextTarget,os);
            if(!operationHighPriority (replace.nextOperation))
            {
                return process_plusminus (os,str+start,str_size-start,replace);
            }
            else
            {
                return process (os,str+start,str_size-start,replace);
            }
        }
    }
    else
    {
        fprintf(stderr, "No valid previous target\n");
        if(str_size<=start)
        {
            fprintf(stderr,"Have new target, but nothing after it - EOD\n");
            return nextTarget;
        }

        if(!operationHighPriority (nextTarget.nextOperation))
        {
            return process_plusminus (os,str+start,str_size-start,nextTarget);
        }
        else
        {
            fprintf(stderr,"Calling process with prev target %s (is valid: %d)\n",
                    nextTarget.name,nextTarget.isValid ());
            return process (os,str+start,str_size-start,nextTarget);
        }
    }

    //never reaches it)
    return Target();
}

Target process_plusminus(std::ostream& os,const char* rest, int rest_size,
                         Target& lowPriorityPrev)
{
    char bogus_str[]="-1";
    Target bogus = Target();
    if(lowPriorityPrev.nextOperation == Operation_Subtract)
    {
        bogus.makeName ();
        bogus.nextOperation=Operation_Multiply;
        bogus.str = bogus_str;
        bogus.str_size = strlen(bogus_str);
        bogus.type = Target::Target_Numeric;

        lowPriorityPrev.nextOperation = Operation_Plus;
    }

    Target therest=process (os,rest,rest_size,bogus);
    if(therest.isValid () && (therest.type == Target::Target_Complex))
    {
        therest = process (os,therest.str,therest.str_size,Target());
    }

    if(!therest.isValid ())
    {
        fprintf(stderr,"Cannot process the rest\n");
       return Target();
    }

    return make_entry (lowPriorityPrev,therest,os);

}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage:%s expression\n\t"
               "Valid symbols: [A-Za-z][0-9][+-/*][()]\n", argv[0]);
        return 3;
    }

    std::ofstream ostm("Makefile.calc");
    if(!ostm.is_open())
    {
        fprintf(stderr,"Cannot write to file Makefile.calc\n");
        return 4;
    }

    Target final = process (ostm,argv[1],strlen(argv[1]),Target());
    if(!final.isValid ())
    {
        fprintf(stderr,"Process routine failed\n");
        return 1;
    }

    if(final.type == Target::Target_Make)
    {
        ostm<<"all: "<<final.name<<"\n\tcp "<<final.name<<".txt result.txt\n\t"
              "cat result.txt\n";
    }
    else
    {
        fprintf(stderr,"Error in algorithm - process returned NOT processed target\n");
        return 2;
    }

    ostm<<"clean:\n\trm -f out*.txt *.exec\n";
    return 0;
}
