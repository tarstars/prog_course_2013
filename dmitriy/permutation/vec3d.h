#ifndef VEC3D_H
#define VEC3D_H

#include <iostream>
#include <math.h>

template<typename T>
class Vec3D
{
    public:
        Vec3D();
        Vec3D(T x, T y, T z) : x1(x), x2(y), x3(z) {}

        //default copy constructor, destructor & assignment operator should be fine here

        Vec3D<T> operator+(const Vec3D<T>& other) const
        {
            return Vec3D<T>((x1+other.x1),(x2+other.x2),(x3+other.x3));
        }

        Vec3D<T> operator*(T mult) const
        {
            return Vec3D<T>(mult*x1,mult*x2,mult*x3);
        }

        template<typename P>
        friend std::ostream& operator<<(std::ostream& os, const Vec3D<P>& vec);

        inline T coord(int index) const
        {
            switch(index)
            {
                case 1:return x1;break;
                case 2:return x2;break;
                case 3:return x3;break;
                default:break;
            }
            std::cerr<<"Invalid vector index "<<index<<"\n";
            return T();
        }
        inline T mod() const
        {
            return sqrt((x1*x1)+(x2*x2)+(x3*x3));
        }
    private:
        T x1,x2,x3;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec3D<T>& vec)
{
    return os<<"("<<vec.x1<<","<<vec.x2<<","<<vec.x3<<")";
}

#endif // VEC3D_H
