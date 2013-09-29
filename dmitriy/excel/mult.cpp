#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout<<"Usage: file1 file2\nOutput: ";
#ifdef OPERATION_PLUS
        std::cout<<"sum";
#else
        std::cout<<"product";
#endif
        std::cout<<std::endl;
        return 1;
    }

    double x,y;
    std::ofstream dest(OFILE);
    std::ifstream first(argv[1]), second(argv[2]);
    while((first>>x)&&(second>>y))
    {
#ifdef OPERATION_PLUS
        dest<<(x+y)<<std::endl;
#else
        dest<<(x*y)<<std::endl;
#endif
    }
    return 0;
}
