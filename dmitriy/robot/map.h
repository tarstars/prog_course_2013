#ifndef MAP_H
#define MAP_H

#include <stdint.h>

class Robot;

class Map
{
    public:
        Map(int x_left, int x_right, int y_bottom, int y_top);
        ~Map();

        void randfill(uint8_t div = 10);

        uint8_t get(int x, int y) const;
        void set(int x, int y, uint8_t value);

        uint8_t get_max() const { return max;}

        inline bool check(int x, int y) const
        {
            return ((x>=left)&&(x<right)&&(y>=bottom)&&(y<top));
        }

        void print() const;
        void print(const Robot& bob) const;
    private:
        int left,right,top,bottom;
        uint8_t* values;
        uint8_t max;

        Map(const Map& other){}
        Map& operator=(const Map& other){return *this;}
};

#endif // MAP_H
