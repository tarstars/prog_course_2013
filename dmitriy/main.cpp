#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

void print_progression(int max)
{
    for(int b=1;b<max;b<<=1)
    {
        std::cout<<b<<std::endl;
    }
}

void print_binary(int val)
{
    printf("%d is (bin): ", val);
    int i = sizeof(int)*8-1;
    while( !((val&((int)1<<i))>>i) && (i>=0) )
    {
        --i;
    }
    for(;i>=0;--i)
    {
        printf("%d", (val&((int)1<<i))>>i);
    }
    printf("\n");
}

void fill_array(int* begin, int* end, int n)
{
    int i=0;
    while((begin < end) && (i++<n))
    {
        *(begin++) = 0;
    }
    while(begin<end)
    {
        *(begin++) = 1;
    }
}

void print_array(int* begin, int* end)
{
    while(begin<end)
    {
        std::cout<<*(begin++)<<",";
    }
    std::cout<<std::endl;
}

void print_array(int* begin, int size)
{
    print_array(begin,begin+size);
}


//Treating array as "BigEndian"
//Not checking if any values != (0|1)
bool prev(int* begin, int* end)
{
    while((begin<end) && !(*begin)) {begin++;}
    while((begin<end) && (*begin)) {begin++;}
    if(begin==end)
    {
        return false;
    }
    int bak = *begin;
    *(begin) = *(begin-1);
    *(begin-1) = bak;
    return true;
}

bool next(int* begin, int* end)
{
    int* runner = end-1;
    bool had_zeros = false;
    while((runner>=begin) && !(*runner))
    {
        had_zeros = true;
        --runner;
    }
    while((runner>=begin) && (*runner))
    {
        --runner;
    }
    //now we got eoa of first zero after 1's
    if(runner<begin)
    {
        return false;
    }

    int bak = *(runner+1);
    *(runner+1) = *(runner);
    *(runner) = bak;
    //now make sure we have THE LEAST one
    if(had_zeros)
    {
        while(prev(runner+1,end)){}
    }
    return true;
}

void twisted_sum(int* begin, int* end)
{
    --end;
    int bak = *(begin++);
    int tmp;
    while(begin<end)
    {
        tmp = *(begin-1)+*(begin+1);
        *(begin-1) = bak;
        bak = tmp;
        ++begin;
    }
    *(begin-1) = bak;
}

void shift_array(int* begin, int* end, int pos)
{
    pos = pos%(end-begin);
    if(!pos)
    {
        return;
    }

    int* bak_array = new int[pos];
    memcpy(bak_array,end-pos,pos*sizeof(int));
    memmove(begin+pos,begin,((end-begin)-pos)*sizeof(int));
    memcpy(begin,bak_array,pos*sizeof(int));
    delete[] bak_array;
}

/*void shift_array_nocpy(int* begin, int* end, int pos)
{
    //TBD
}*/

void cin_sum()
{
    int val=0;
    int sum=0;
    while(std::cin>>val)
    {
        sum+=val;
    }
    std::cout<<"Sum: "<<sum<<std::endl;
}

void cin_average()
{
    int val = 0;
    int total = 0;
    int average = 0;
    while(std::cin>>val)
    {
        average+=val;
        ++total;
    }
    if(total)
    {
        std::cout<<"Average: "<<((double)average/total)<<std::endl;
    }
    else
    {
        std::cout<<"No numbers\n";
    }
}

void cin_stddiv()
{
    int val = 0;
    int total = 0;
    double average = 0;
    double std = 0;
    while(std::cin>>val)
    {
        average+=val;
        std+=val*val;
        ++total;
    }

    if(total)
    {
        average/=total;
        std/=total;
        std::cout<<"Average: "<<average<<"; Std: "
                <<sqrt(std-average*average)<<std::endl;
    }
    else
    {
        std::cout<<"No numbers\n";
    }
}

void polynom()
{
    double x;
    if(!(std::cin>>x))
    {
        std::cout<<"Empty data\n";
        return;
    }
    double a=0;
    int n = 0;
    double value = 0;
    while(std::cin>>a)
    {
        value += pow(x,n)*a;
    }
    std::cout<<"Z(x)="<<value<<std::endl;
}

int main()
{
    print_progression(2000);

    {
        int array2[] = {1,2,3,4,5,6,7,8};
        twisted_sum(array2,array2+sizeof(array2)/sizeof(int));
        print_array(array2,array2+sizeof(array2)/sizeof(int));
    }

    {
        int array2[] = {1,2,3,4,5,6,7,8};
        shift_array(array2,array2+sizeof(array2)/sizeof(int),3);
        print_array(array2,array2+sizeof(array2)/sizeof(int));
    }

    {
        int bin_array[10];
        fill_array(bin_array,bin_array+10,6);
        do
        {
            print_array(bin_array,bin_array+10);
        }while(next(bin_array,bin_array+10));
    }

    {
        int val = 20;
        print_binary(val);
    }
    return 0;
}

