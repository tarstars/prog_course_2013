#include <iostream>

#include "vec3d.h"
#include "permutation.h"

int main(void)
{
    Vec3D<double> vec1(1,1,1);
    std::cout<<vec1<<std::endl;
    std::cout<<vec1.mod()<<std::endl;
    std::cout<<vec1*5<<std::endl;
    Vec3D<double> vec2(-1,1,1);
    std::cout<<vec2<<std::endl;
    std::cout<<(vec1+vec2)<<std::endl;

    Permutation<4> perm1;
    perm1.swap(1,4);
    std::cout<<perm1<<std::endl;
    Permutation<4> perm2;
    perm2.swap(2,3);
    perm2.swap(2,4);
    std::cout<<perm2<<std::endl;
    std::cout<<(perm1*perm2)<<std::endl;

    return 0;
}
