#include "robot.h"
#include "map.h"

Robot::Robot() :x(0),y(0), value(0)
{
}

void Robot::right()
{
    ++x;
    std::cout<<*this<<std::endl;
}

void Robot::left()
{
    --x;
    std::cout<<*this<<std::endl;
}

void Robot::up()
{
    ++y;
    std::cout<<*this<<std::endl;
}

void Robot::down()
{
    --y;
    std::cout<<*this<<std::endl;
}

bool Robot::check(const Map& map)
{
    if(!map.check(x,y))
    {
        std::cerr<<"Robot left the field\n";
        return false;
    }

    int val = map.get(x,y);
    if(val==(value+1))
    {
        ++value;
        std::cout<<"Robot promoted to "<<value<<"\n";
        if(value==map.get_max())
        {
            std::cout<<"Congratulations!)))\n";
            return true;
        }
    }
    else
    {
        std::cout<<"Sorry, "<<val<<" no hit\n";
    }
    return false;
}
