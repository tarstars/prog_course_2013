#include <stdlib.h>

#include <iostream>
#include <vector>
#include <list>

#define NAME_START 'a'

template<typename T>
std::ostream& print(std::ostream& os, T itb, T ite)
{
    while(itb!=ite)
    {
        os<<(*(itb++))<<", ";
    }
    return os;
}

template<typename T>
bool make_move(std::list<T>& list1, std::list<T>& list2)
{
    if(!list1.size())
    {
       return false;
    }

    list2.push_back(list1.back());
    list1.pop_back();
    return true;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout<<"Specify disk count\n";
        return 1;
    }
    int disk_count = atoi(argv[1]);
    if((disk_count < 0) || (disk_count > ('z'-NAME_START)))
    {
        std::cout<<"Invalid disk count "<<disk_count<<"\n";
        return 2;
    }
    static const int towers=3;

    std::vector<std::list<char> > dat(towers);

    for(int i=0;i<disk_count;++i)
    {
        dat[0].push_back(NAME_START+i);
    }

    std::cout<<"Tower 1:\n";
    print(std::cout,dat[0].begin(),dat[0].end())<<std::endl;

    int t1, t2;
    std::cout<<"Insert tower numbers [1-3]\n";

    while(std::cin>>t1>>t2)
    {
        --t1;--t2;

        if((t1>=towers)||(t2>=towers)||(t1<0)||(t2<0))
        {
            std::cout<<"Invalid numbers!\n";
            return 3;
        }
        make_move(dat[t1],dat[t2]);
        for(int i=0;i<towers;++i)
        {
            std::cout<<"Tower "<<i+1<<":\n";
            print(std::cout,dat[i].begin(),dat[i].end())<<std::endl;
        }
    }
    return 0;
}
