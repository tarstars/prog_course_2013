#include "map.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <iomanip>

#include "robot.h"

Map::Map(int x_left, int x_right, int y_bottom, int y_top) :
    left(x_left), right(x_right+1), top(y_top+1), bottom(y_bottom)
{
    values = new uint8_t[(right-left)*(top-bottom)];
    memset(values,0,sizeof(values));
    max=0;
}

Map::~Map()
{
    delete[] values;
}

void Map::randfill(uint8_t div)
{
    srand(time(0));
    max = 0;
    int val;

    for(int i = 0; i < (top-bottom); ++i)
    {
        for(int j = 0 ; j < (right-left);++j)
        {
            val = rand()%div;
            values[i*(right-left)+j] = val;
            if(max<val)
            {
                max=val;
            }
        }
    }
}

uint8_t Map::get(int x, int y) const
{
    if(check(x,y))
    {
        return values[(y-bottom)*(right-left)+(x-left)];
    }
    return 0;
}

void Map::set(int x, int y, uint8_t value)
{
    if(check(x,y))
    {
        values[(y-bottom)*(right-left)+(x-left)] = value;
        if(value>max)
        {
            max=value;
        }
    }
}

void Map::print() const
{
    char prev = std::cout.fill('0');
    int width = ( (max>=100) ? 3 : ( (max>=10) ? 2 : 1 ) );

    for(int i = (top-bottom)-1; i >=0 ; --i)
    {
        for(int j = 0 ; j < (right-left);++j)
        {
            std::cout<<std::setw(width)<<(int)values[i*(right-left)+j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout.fill(prev);
}

void Map::print(const Robot& bob) const
{
    int width = ( (max>=100) ? 3 : ( (max>=10) ? 2 : 1 ) );
    char prev = std::cout.fill('0');

    for(int i = (top-bottom)-1; i >=0 ; --i)
    {
        for(int j = 0 ; j < (right-left);++j)
        {
            if((j==(bob.get_x()-left))&&(i==(bob.get_y()-bottom)))
            {
                if(width==3)
                {
                    std::cout<<"~R~ ";
                }
                else if (width==2)
                {
                    std::cout<<">< ";
                }
                else
                {
                    std::cout<<"R ";
                }
            }
            else
            {
                std::cout<<std::setw(width)<<(int)values[i*(right-left)+j]<<" ";
            }
        }
        std::cout<<"\n";
    }

    std::cout.fill(prev);
}
