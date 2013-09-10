#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>

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

void polynome()
{
    double x;
    if(!(std::cin>>x))
    {
        std::cout<<"Empty data\n";
        return;
    }
    std::cout<<"X="<<x<<std::endl;
    double a=0;
    int n = 0;
    double value = 0;
    while(std::cin>>a)
    {
        value += pow(x,n)*a;
        ++n;
    }
    std::cout<<"Z(x)="<<value<<std::endl;
}

void polynome2()
{
    double x;
    if(!(std::cin>>x))
    {
        std::cout<<"Empty data\n";
        return;
    }
    std::cout<<"X="<<x<<std::endl;
    double a=0;
    //int n = 0;
    double value = 0;
    while(std::cin>>a)
    {
        value = value*x+a;
        //++n;
    }
    std::cout<<"Z(x)="<<value<<std::endl;
}

void polynome_derive()
{
    double x;
    if(!(std::cin>>x))
    {
        std::cout<<"Empty data\n";
        return;
    }
    std::cout<<"X="<<x<<std::endl;
    double a=0;
    int n = 1;
    double value = 0;
    if(!(std::cin>>a))
    {
        std::cout<<"Invalid data - X present, but no coefficients\n";
        return;
    }

    while(std::cin>>a)
    {

        value += pow(x,n-1)*a*n;
        ++n;
    }
    std::cout<<"Z'(x)="<<value<<std::endl;
}

void polynome_derive2()
{
    double x;
    if(!(std::cin>>x))
    {
        std::cout<<"Empty data\n";
        return;
    }
    std::cout<<"X="<<x<<std::endl;
    double a=0;
    double value_aux = 0;
    double value_main = 0;
    while(std::cin>>a)
    {
        value_main = value_main*x+value_aux;
        value_aux = value_aux*x+a;
    }
    std::cout<<"Z'(x)="<<value_main<<std::endl;
}

int euclid(int a, int b)
{
    int c;
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }

    while(c=(a%b))
    {
        a=b;
        b=c;
    }
    return b;
}

class Coeffs
{
    public:
        Coeffs(int Av,int Bv) : A(Av), B(Bv),
            a_coeff(0), b_coeff(0){}
        Coeffs(int Av,int Bv,int ac, int bc) : A(Av), B(Bv),
            a_coeff(ac), b_coeff(bc){}
        Coeffs(const Coeffs& other) : A(other.A), B(other.B),
            a_coeff(other.a_coeff), b_coeff(other.b_coeff) {}

        Coeffs& operator=(const Coeffs& other)
        {
            A=other.A;
            B=other.B;
            a_coeff=other.a_coeff;
            b_coeff=other.b_coeff;
            return *this;
        }

        inline int value() const { return a_coeff*A + b_coeff*B;}
        inline int alpha() const { return a_coeff;}
        inline int beta()  const { return b_coeff;}
        void setValue(int ac, int bc)
        {
            a_coeff= ac;
            b_coeff = bc;
        }

        Coeffs& operator+(const Coeffs& other)
        {
            a_coeff+=other.a_coeff;
            b_coeff+=other.b_coeff;
            return *this;
        }
        Coeffs& operator-(const Coeffs& other)
        {
            a_coeff-=other.a_coeff;
            b_coeff-=other.b_coeff;
            return *this;
        }
        Coeffs& operator*(int mult)
        {
            a_coeff*=mult;
            b_coeff*=mult;
            return *this;
        }

        int operator%(const Coeffs& other)
        {
            return (value()%other.value());
        }
        int operator/(const Coeffs& other)
        {
            return (value()/other.value());
        }

    private:
        int A;
        int B;

        int a_coeff;
        int b_coeff;
};

void euclid_coeffs(int a, int b)
{
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    Coeffs rc0(a,b,1,0),rc1(a,b,0,1),rc2(a,b);
    while(rc0%rc1)
    {
        rc2=rc0-rc1*(rc0/rc1);
        rc0=rc1;
        rc1=rc2;
    }
    if(rc1.value() > 1)
    {
        rc1=rc0-rc1*(rc0/rc1);
    }
    std::cout<<rc1.value()<<" = "<<rc1.alpha()<<"*"<<a<<" + "<<rc1.beta()<<"*"<<b<<std::endl;
}

int factorial(int N)
{
    return (N>1) ? N*factorial(N-1) : 1;
}

int fibonacci(int N)
{
    if(N<=0)
    {
        return 0;
    }
    else if(N==1)
    {
        return 1;
    }

    return fibonacci(N-2)+fibonacci(N-1);
}

int binom(int N, int k)
{
    if(k<0)
    {
        return 0;
    }

    if(N>0)
    {
        if(k>N)
        {
            return 0;
        }
        else if((k==0)||(k==N))
        {
            return 1;
        }
        return binom(N-1,k-1) + binom(N-1,k);
    }
    else if(N<0)
    {
        return ( (k%2) ? -1 : 1) * binom(k-N-1,k);
    }
    //else: N==0
    return ((k==0) ? 1: 0);
}

void hanoi(int tower1, int tower2, int disks)
{
    if(disks==1)
    {
        std::cout<<tower1<<"->"<<tower2<<std::endl;
    }
    else if(disks<1)
    {
        std::cout<<"Error\n";
    }
    else
    {
        int tower3=6-tower1-tower2;
        hanoi(tower1,tower3,disks-1);
        hanoi(tower1,tower2,1);
        hanoi(tower3,tower2,disks-1);
    }
}

int bin_euclid(int a, int b)
{
    //std::cout<<"Requested bin euclid for "<<a<<","<<b<<"\n";
    //some checks to make it fool-proof
    if(!a)
    {
        return b;
    }
    else if(!b)
    {
        return a;
    }
    else if(a==b)
    {
        return a;
    }

    if(a<0)
    {
        a*=-1;
    }
    if(b<0)
    {
        b*=-1;
    }

    //a>0, b>0
    int gcd=1;
    while(!(a&0x01) && !(b&0x01)) //both even
    {
        gcd<<=1;
        a>>=1;
        b>>=1;
    }
    while(!(a&0x01)){a>>=1;}
    while(!(b&0x01)){b>>=1;}

    //both odd; do not check a>=b - will be corrected while fool-proof checks))
    if((a==1)||(b==1))
    {
        return gcd;
    }
    return gcd*bin_euclid((a-b)/2,b);
}

void print_help()
{
    std::cout<<"Options:\n\t"
               "-p\tprint progression\n\t"
               "-t\tarray with sum of elements\n\t"
               "-s\tshift array\n\t"
               "-n\tperform \"next\" operation\n\t"
               "-b\tprint int in binary format\n\t"
               "-cs\tcalculate sum from standard input\n\t"
               "-ca\tcalculate average from standard input\n\t"
               "-cd\tcalculate average & standard declination from standard input\n\t"
               "-cpv1\tcalculate polynome value (format: x, a0, a1, ...)\n\t"
               "-cpd1\tcalculate polynome derivative (format x, a0, a1, ...)\n\t"
               "-cpv2\tcalculate polynome value (format: x, a(n), a(n-1), ...)\n\t"
               "-cpd2\tcalculate polynome derivative (format x, a(n), a(n-1), ...)\n\t"
               "-gcd\tcalculate greatest common divisor\n\t"
               "-gcd2\tcalculate greatest common divisor (binary method)\n\t"
               "-ec\tcalculate coefficients based on gcd\n\t"
               "-fact\tcalculate factorial\n\t"
               "-fib\tcalculate fibonacci numbers\n\t"
               "-binom\tcalculate binomial coefficient\n\t"
               "-hanoi\n\tsolve hanoi towers problem\n\t"
               "\n";
}

#define ARG(x) (strcmp(argv[1],(x)) == 0)

int main(int argc, char *argv[])
{
    if(argc<=1)
    {
        print_help();
        return 1;
    }

    if(ARG("-p"))
    {
        print_progression(2000);
    }
    else if(ARG("-t"))
    {
        int array2[] = {1,2,3,4,5,6,7,8};
        twisted_sum(array2,array2+sizeof(array2)/sizeof(int));
        print_array(array2,array2+sizeof(array2)/sizeof(int));
    }
    else if(ARG("-s"))
    {
        int array2[] = {1,2,3,4,5,6,7,8};
        shift_array(array2,array2+sizeof(array2)/sizeof(int),3);
        print_array(array2,array2+sizeof(array2)/sizeof(int));
    }
    else if(ARG("-n"))
    {
        int bin_array[10];
        fill_array(bin_array,bin_array+10,6);
        do
        {
            print_array(bin_array,bin_array+10);
        }while(next(bin_array,bin_array+10));
    }
    else if(ARG("-b"))
    {
        int val = 20;
        print_binary(val);
    }
    else if(ARG("-cs"))
    {
        cin_sum();
    }
    else if(ARG("-ca"))
    {
        cin_average();
    }
    else if(ARG("-cd"))
    {
        cin_stddiv();
    }
    else if(ARG("-cpv1"))
    {
        polynome();
    }
    else if(ARG("-cpv2"))
    {
        polynome2();
    }
    else if(ARG("-cpd1"))
    {
        polynome_derive();
    }
    else if(ARG("-cpd2"))
    {
        polynome_derive2();
    }
    else if(ARG("-gcd")||ARG("-gcd2"))
    {
        int a=1,b=1;
        std::cout<<"A: ";
        std::cin>>a;
        std::cout<<"B: ";
        std::cin>>b;
        if(ARG("-gcd"))
        {
            std::cout<<"gcd("<<a<<","<<b<<")="<<euclid(a,b)<<"\n";
        }
        else
        {
            std::cout<<"gcd("<<a<<","<<b<<")="<<bin_euclid(a,b)<<"\n";
        }
    }
    else if(ARG("-ec"))
    {
        int a=1,b=1;
        std::cout<<"A: ";
        std::cin>>a;
        std::cout<<"B: ";
        std::cin>>b;
        euclid_coeffs(a,b);
    }
    else if(ARG("-fact"))
    {
        int N=0;
        std::cout<<"N: ";
        std::cin>>N;
        std::cout<<"N!="<<factorial(N)<<std::endl;
    }
    else if(ARG("-fib"))
    {
        int n=0;
        std::cout<<"n: ";
        std::cin>>n;
        std::cout<<"fibonacci("<<n<<")="<<fibonacci(n)<<std::endl;
    }
    else if(ARG("-binom"))
    {
        int n=0,k=0;
        std::cout<<"n: ";
        std::cin>>n;
        std::cout<<"k: ";
        std::cin>>k;
        std::cout<<"C("<<n<<","<<k<<")="<<binom(n,k)<<std::endl;
        if(factorial(n-k)&&factorial(n))
        {
        std::cout<<"Check: "<<(((k<=n)&&(k>=0))? factorial(n)/(factorial(k)*factorial(n-k)) : 0)
                   <<std::endl;
        }
        else
        {
            std::cout<<"Cannot check - factorial out of bounds\n";
        }
    }
    else if(ARG("-hanoi"))
    {
        int disks=1;
        std::cout<<"Number of Disks: ";
        std::cin>>disks;
        hanoi(1,2,disks);
    }
    /*else if(ARG("-vect"))
    {
        std::vector<double> dat(5);
        for(int i = 0; i < (int)dat.size(); ++i)
        {
            dat[i] = i;
        }

        std::vector<double>::iterator it = dat.begin();
        std::cout<<"1) "<<*it<<"\n";
        ++it;
        std::cout<<"2) "<<*it<<"\n";
        it+=2;
        std::cout<<"3) "<<*it<<"\n";
    }*/
    else
    {
        std::cout<<"Unknown argument "<<argv[1]<<std::endl;
        print_help();
        return 1;
    }

    return 0;
}

