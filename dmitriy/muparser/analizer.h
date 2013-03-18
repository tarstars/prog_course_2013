#ifndef ANALIZER_H_
#define ANALIZER_H_

#include <string.h>

#include "defines.h"

inline bool mathoperand(char c)
{
    return ((c=='+')||(c=='-')||(c=='/')||(c=='*'));
}

inline bool isdigit(char c)
{
    return ((c>='0')&&(c<='9'));
}

inline bool ischar(char c)
{
    return ( ((c>='a')&&(c<='z'))||((c>='A')&&(c<='Z')) );
}

inline bool numbersonly(const char* str, int str_size)
{
    if(str_size<=0)
    {
        return false;
    }

    if(isdigit (*str) || (*str=='-') || (*str=='+'))
    {
        ++str;
        for(int i = 1 ; i < str_size; ++i)
        {
            if(!isdigit(*str++))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}

inline bool charsonly(const char* str, int str_size)
{
    for(int i = 0; i < str_size; ++i)
    {
        if( !ischar(*str++) )
        {
            return false;
        }
    }
    return true;
}

inline bool operationHighPriority(OperationType type)
{
    return ((type==Operation_Multiply)||(type==Operation_Divide));
}

#endif  //ANALIZER_H_
