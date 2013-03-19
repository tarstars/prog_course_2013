#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

#include "robot.h"
#include "map.h"

int main(void)
{
    Map map(-10,10,-10,10);
    map.randfill(15);
    Robot bob;
    map.print(bob);
    std::cout<<"Format: [cmd][num*]\n"
               "Cmd: [a-left, d-right, w-up, x-down, other key - exit]\n"
               "Num: (optioanl, default 1) number of steps\n";
    std::string cmd;
    int steps_count;
    int steps = 0;
    while(true)
    {
        cmd.clear();
        getline(std::cin,cmd);
        if(cmd.size() < 1)
        {
            std::cerr<"Invalid command";
            continue;
        }
        bool exit=false;
        if(cmd.size()>1)
        {
            std::string num(cmd.begin()+1,cmd.end());
            std::stringstream myStream(num);
            if (!(myStream >> steps_count))
            {
                std::cerr<<"Invalid number\n";
                steps_count=1;
            }
        }
        else
        {
            steps_count=1;
        }

        switch(cmd.at(0))
        {
            case 'd':for(int i=0;i<steps_count;++i){bob.right();++steps;}break;
            case 'a':for(int i=0;i<steps_count;++i){bob.left(); ++steps;}break;
            case 'w':for(int i=0;i<steps_count;++i){bob.up();   ++steps;}break;
            case 'x':for(int i=0;i<steps_count;++i){bob.down(); ++steps;}break;
            case 'm':
            {
                map.print(bob);
                continue;
            }
            default:
            {
                std::cerr<<"Got char "<<(int)cmd.at(0)<<" - goodbye)\n";
                exit=true;
                break;
            }
        }
        if(exit)
        {
            break;
        }

        if(bob.check(map))
        {
            std::cout<<"Your result: "<<steps<<" steps\n";
            break;
        }
    }
    return 0;
}
