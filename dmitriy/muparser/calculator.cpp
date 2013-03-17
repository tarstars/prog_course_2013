#include <iostream>
#include <fstream>
#include <vector>

#include <stdlib.h>
#include <limits>

#include "analizer.h"

#define RESERVE_CHUNK 128

inline double operation(double x1, double x2)
{
#ifdef OPERATION_PLUS
    return x1+x2;
#elif defined OPERATION_SUBT
    return x1-x2;
#elif defined OPERATION_MULT
    return x1*x2;
#elif defined OPERATION_DIVD
    return ( (x2!=0.) ? x1/x2 : std::numeric_limits<double>::quiet_NaN());
#else
    return 0;
#endif
}

inline void process_file(const char* fname, std::vector<double>& val)
{
    std::ifstream istm(fname);

    val.clear ();
    int reserved = RESERVE_CHUNK;
    val.reserve (reserved);

    double in;
    while(istm>>in)
    {
        if(!reserved)
        {
            val.reserve (val.size ()+RESERVE_CHUNK);
            reserved = RESERVE_CHUNK;
        }

        val.push_back (in);
        --reserved;
    }
}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cerr<<"Usage: file1/var1 file2/var2\nOutput (to stdout): ";
#ifdef OPERATION_PLUS
        std::cerr<<"sum";
#elif defined OPERATION_SUBT
        std::cerr<<"subtract";
#elif defined OPERATION_MULT
        std::cerr<<"product";
#elif defined OPERATION_DIVD
        std::cerr<<"divide";
#else
#error "Unknown operation"
#endif
        std::cerr<<std::endl;
        return 1;
    }

    std::vector<double> var1, var2;

    if(numbersonly(argv[1],strlen(argv[1])))
    {
        var1.push_back (atof(argv[1]));
    }
    else
    {
        process_file (argv[1],var1);
    }

    if(numbersonly(argv[2],strlen(argv[2])))
    {
        var2.push_back (atof(argv[2]));
    }
    else
    {
        process_file (argv[2],var2);
    }

    if(!var1.size () || !var2.size ())
    {
        std::cerr<<"Nothing to process: var1 size "<<var1.size ()
                <<"; var2 size "<<var2.size ()<<"\n";
        return 2;
    }

    if(var1.size () == 1)
    {
        for(std::vector<double>::const_iterator it = var2.begin();it<var2.end();++it)
        {
            std::cout<<operation (var1.at(0),*it)<<std::endl;
        }
    }
    else if(var2.size ()==1)
    {
        for(std::vector<double>::const_iterator it = var1.begin();it<var1.end();++it)
        {
            std::cout<<operation (*it, var2.at(0))<<std::endl;
        }

        for(int i = 0, j = 0; i < 6; ++i);
    }
    else if(var1.size ()==var2.size ())
    {
        for(std::vector<double>::const_iterator it1 = var1.begin(),
            it2 = var2.begin();it1<var1.end();++it1,++it2)
        {
            std::cout<<operation (*it1, *it2)<<std::endl;
        }
    }
    else
    {
        std::cerr<<"WARNING: vector dimension mismatch: "<<var1.size ()<<" vs "<<var2.size ()<<"\n";
        int min_size = std::min(var1.size (),var2.size ());
        for(int i = 0;i<min_size;++i)
        {
            std::cout<<operation (var1.at(i),var2.at(i))<<std::endl;
        }
    }

    return 0;
}
