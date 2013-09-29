#include <list>
#include <string>
#include <iostream>

int main(void)
{
    std::string input;
    std::list<std::string> dat;

    while(std::cin>>input)
    {
        dat.push_back(input);
    }
    for(auto it = dat.cend();it!=dat.cbegin();)
    {
        std::cout<<"\""<<*(--it)<<"\" ";
    }
    std::cout<<"\n";
    return 1;
}
