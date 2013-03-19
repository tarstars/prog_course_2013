#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

class Map;

class Robot
{
    public:
        friend std::ostream& operator<<(std::ostream& os, const Robot& r);

        Robot();
        void right();
        void left();
        void up();
        void down();

        bool check(const Map& map);

        inline int get_x() const { return x;}
        inline int get_y() const { return y;}
    private:
        int x,y;
        int value;
};

inline std::ostream& operator<<(std::ostream& os, const Robot& r)
{
    return os<<"("<<r.x<<";"<<r.y<<")";
}

#endif // ROBOT_H
