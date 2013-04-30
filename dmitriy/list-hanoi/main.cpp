#include <stdlib.h>

#include <iostream>
#include <vector>
#include <list>

#include <string.h>

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

void hanoi_solver(int tower1, int tower2, int disks)
{
    if(disks==1)
    {
        std::cout<<tower1<<" "<<tower2<<std::endl;
    }
    else if(disks<1)
    {
        std::cerr<<"Error\n";
    }
    else
    {
        int tower3=6-tower1-tower2;
        hanoi_solver(tower1,tower3,disks-1);
        hanoi_solver(tower1,tower2,1);
        hanoi_solver(tower3,tower2,disks-1);
    }
}

void print_state(const std::vector<std::list<char> >& dat)
{
    for(int i=0;i<dat.size();++i)
    {
        std::cout<<"Tower "<<(i+1)<<": ";
        print(std::cout,dat[i].begin(),dat[i].end())<<std::endl;
    }
    std::cout<<"------------------------------------\n";
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout<<"Specify mode (-s[--solver] or -e[--emulator])\n";
        return 1;
    }
    static const int disk_count = 4;
    static const int towers=3;

    if((strcmp(argv[1],"-s")==0) || (strcmp(argv[1],"--solver")==0))
    {
        hanoi_solver(1,3,3);
        return 0;
    }
    else if((strcmp(argv[1],"-e")==0)||(strcmp(argv[1],"--emulator")==0))
    {
        std::vector<std::list<char> > dat(towers);
    
        for(int i=0;i<disk_count;++i)
        {
            dat[0].push_back(NAME_START+i);
        }

        print_state(dat);    
        int t1, t2;

        while(std::cin>>t1>>t2)
        {
           --t1;--t2;
           if((t1>=towers)||(t2>=towers)||(t1<0)||(t2<0))
           {
               std::cerr<<"Invalid numbers!\n";
               return 3;
           }
           make_move(dat[t1],dat[t2]);
           print_state(dat);
       }
       return 0;
    }
    std::cerr<<"Invalid mode "<<argv[1]<<std::endl;
    return 1;
}
