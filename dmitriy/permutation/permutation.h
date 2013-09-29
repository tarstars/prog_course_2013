#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <iostream>
#include <utility>

template<int N>
class Permutation
{
    public:
        Permutation()
        {
            int* ptr = values;
            for(int i = 1; i <= N ; ++i)
            {
                *ptr++=i;
            }
        }

        //Warning!!! math indices: i.e from 1 to N (not from 0)
        inline void swap(int i1, int i2)
        {
            if((i1>0)&&(i1<=N)&&(i2>0)&&(i2<=N))
            {
                std::swap(*(values+i1-1), *(values+i2-1));
            }
        }

        Permutation operator*(const Permutation& other)
        {
            Permutation ret;
            for(int i = 0; i < N; ++i)
            {
                ret.values[i]=this->values[other.values[i]-1];
            }
            return ret;
        }

        template<int K>
        friend std::ostream& operator<<(std::ostream& os, const Permutation<K>& p);

    private:
        int values[N];

        Permutation(const Permutation& other) {}
        Permutation& operator=(const Permutation& other) {return *this;}
};

template<int K>
std::ostream& operator<<(std::ostream& os, const Permutation<K>& p)
{
    os<<"(";
    for(int i=0;i<(K-1);++i)
    {
        os<<p.values[i]<<",";
    }
    if((K-1)>0)
    {
        os<<p.values[K-1];
    }
    return os<<")";
}

#endif // PERMUTATION_H
