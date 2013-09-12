#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <fstream>

#include <string.h>
#include <stdlib.h>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979
#endif

typedef complex<double> unit;
typedef vector<unit>    myvector;
typedef struct Vector3D
{
    double x;
    double y;
    double z;
} Point;

typedef struct GravParams
{
    Point start;
    Point speed;
    double linear_friction;
} GravParams;

ostream& operator<<(ostream& os, const myvector& z)
{
    os<<"(";
    for(int i = 0; i < (int)z.size(); ++i)
    {
        os<<z.at(i).real()<<"+ i*"<<z.at(i).imag();
    }
    os<<")";
    return os;
}

ostream& operator<<(ostream& os, const Point& p)
{
    return os<<"("<<p.x<<";"<<p.y<<";"<<p.z<<")";
}

myvector operator *(const myvector& z, double d)
{
    myvector ret(z);
    for(int i = 0;i<(int)z.size();++i)
    {
        ret[i]*=d;
    }
    return ret;
}

myvector operator +(const myvector& z1, const myvector& z2)
{
    if(z1.size() == z2.size())
    {
        myvector ret(z1.size());
        for(int i = 0 ; i < (int)z1.size(); ++i)
        {
            ret[i] = z1.at(i)+z2.at(i);
        }
        return ret;
    }

    throw(string("operator+: inconsistent dimensions"));
    return myvector(0);
}

/////////////////////////////////

enum FuncType
{
    Func_Sin,
    Func_Square,
    Func_Grav
};

myvector fsin(const myvector& z, double t, const void* args)
{
    static const size_t dim = 2;
    (void)t;
    (void)args;

    if(z.size()!=dim)
    {
        throw(string("exception: vector dimension mismatch"));
    }

    myvector ret(dim);
    ret[0] = -z[1];
    ret[1] =    z[0];
    return ret;
}

myvector fpow(const myvector& z, double t, const void* args)
{
    static const size_t dim = 1;
    (void)t;
    (void)args;

    if(z.size()!=dim)
    {
        throw(string("exception: vector dimension mismatch"));
    }

    myvector ret(dim);
    ret[0] = sqrt(z[0]);

    return ret;
}

myvector fgrav(const myvector& z, double t, const void* args)
{
    static const size_t dim = 3;
    (void)t;
    const GravParams* params = (GravParams*)args;

    if(!params || (z.size()!=dim))
    {
        throw(string("exception: vector dimension mismatch"));
    }

    myvector ret(dim);

    ret[0] = params->speed.x - params->linear_friction;
    ret[1] = params->speed.y - params->linear_friction;
    ret[2] = params->speed.z - params->linear_friction - 9.8*t;

    return ret;
}

/////////////////////////////////////////

myvector init_sin()
{
    myvector ret(2);
    ret[0] = 1;
    ret[1] = 0;

    return ret;
}

myvector init_pow()
{
    myvector ret(1);
    ret[1]=1;
    return ret;
}

myvector init_grav(const GravParams& params)
{
    myvector ret(3);
    ret[0] = params.start.x;
    ret[1] = params.start.y;
    ret[2] = params.start.z;

    return ret;
}

//////////////////////////////////////////////

myvector one_step(const myvector& zp, double t, double &dt,
                  myvector (*func)(const myvector&, double, const void*), const void* args)
{
    myvector k1 = func(zp       ,t     ,args)*dt;
    myvector k2 = func(zp+k1*0.5,t+dt/2,args)*dt;
    myvector k3 = func(zp+k2*0.5,t+dt/2,args)*dt;
    myvector k4 = func(zp+k3    ,t     ,args)*dt;

    return zp+(k1+k2*2+k3*2+k4)*(1./6);
}

void calculation(FuncType type,const void* args)
{
    myvector (*fptr)(const myvector&,double,const void*) = NULL;
    myvector z;
    double z0 = 0;

    switch(type)
    {
    case Func_Sin:
    {
        z = init_sin();
        fptr = fsin;
        break;
    }
    case Func_Square:
    {
        z = init_pow();
        fptr = fpow;
        break;
    }
    case Func_Grav:
    {
        z = init_grav(*((GravParams*)args));
        z0 = z[2].real();
        fptr = fgrav;
        break;
    }
    }

    double t = 0;
    double dt = 1e-2;
    if(type != Func_Grav)
    {
        while(t<5)
        {
            z = one_step(z,t,dt,fptr,args);
            cout<<t;
            for(int i=0;i<(int)z.size();++i)
            {
                cout<<" "<<real(z[i]);
            }
            cout<<endl;
            t+=dt;
        }
    }
    else
    {
        vector<Point> positions;
        positions.push_back(((GravParams*)args)->start);
        do
        {
            cout<<real(z[0])<<" "<<real(z[1])<<" "<<real(z[2])<<endl;
            //output to povray
            Point curpoint = {real(z[0]),real(z[1]),real(z[2])};
            positions.push_back(curpoint);

            z = one_step(z,t,dt,fptr,args);
            t+=dt;
        }while(z[2].real()>z0);

        ofstream povfile,inifile;
        povfile.open("gravgun.pov",ofstream::out);
        inifile.open("gravgun.ini",ofstream::out);

        inifile<<"Initial_Frame = 1\nFinal_Frame = "<<positions.size()
               <<"\n\nInitial_Clock = 0\nFinal_Clock = "<<(positions.size()-1)
               <<"\nInput_File_Name = \"gravgun.pov\"\n";
        povfile<<"#version 3.7;\n\nglobal_settings {assumed_gamma 1.0}\n\n";
        povfile<<"#declare positions = array["<<positions.size()<<"][3];\n";
        for(int i = 0 ; i < (int)positions.size(); ++i)
        {
            povfile<<"#declare positions["<<i<<"][0] = "<<positions.at(i).y<<";\n";
            povfile<<"#declare positions["<<i<<"][1] = "<<positions.at(i).z<<";\n";
            povfile<<"#declare positions["<<i<<"][2] = "<<-1*positions.at(i).x<<";\n";
        }

        Point povcamera;
        if(fabs(positions.at(0).x) < 5)
        {
            povcamera.x = (((GravParams*)args)->speed.x < 0) ? 30. : -30.;
        }
        else
        {
            povcamera.x = (((GravParams*)args)->speed.x < 0) ? 3.*positions.at(0).x : -1.*positions.at(0).x;
        }
        if(fabs(positions.at(0).y) < 5)
        {
            povcamera.y = (((GravParams*)args)->speed.y < 0) ? 45. : -45.;
        }
        else
        {
            povcamera.y = (((GravParams*)args)->speed.y < 0) ? 4.*positions.at(0).y : -2.*positions.at(0).y;
        }
        povcamera.z = (fabs(positions.at(0).z) < 5) ? 25. : (positions.at(0).z + 3.*fabs(positions.at(0).z));

        Point povlight = {povcamera.x, -1*povcamera.y, povcamera.z};

        povfile<<"\n\ncamera {\n    location <"
               <<povcamera.y<<","<<povcamera.z<<","<<-1*povcamera.x
               <<">\n    look_at <"
               <<positions.at(0).y<<", "<<positions.at(0).z<<", "<<-1*positions.at(0).x
               <<">\n    angle 30\n}\n\n";

        povfile<<"light_source {\n    <"
               <<povlight.y<<","<<povlight.z<<","<<-1*povlight.x
               <<">\n    color <1, 1, 1>\n}\n\n";

        povfile<<"sky_sphere {\n    pigment {\n        gradient y\n        color_map {\n"
                 "            [0.0 color rgb<1,1,1>]\n"
                 "            [0.8 color rgb<0.1,0.25,0.75>]\n            [1.0 color rgb<0.1,0.25,0.75>]\n"
                 "        }\n        scale 2\n        translate -1\n    }\n}\n\n";

        povfile<<"sphere {\n    <positions[clock][0],positions[clock][1],positions[clock][2]>, 1\n"
                 "pigment { rgb<0.5,0.5,0.5> }\n"
                 "    finish {\n        ambient .2\n        diffuse .6\n        specular .75\n"
                 "        roughness .001\n    }\n}\n\n";

        povfile<<"plane{ <0,1,0>, "
               <<((fabs(positions.at(0).z) < 2) ? -2 : (positions.at(0).z-0.1*fabs(positions.at(0).z)))
               <<"\n    texture{\n        pigment{color rgb<0.35,0.65,0.0>*0.8}\n"
                 "normal {bumps 0.75 scale 0.015}\n    }\n}\n";
    }
}

bool getcartesian(const char* data, Vector3D* out, char border='{')
{
    size_t data_size = strlen(data);

    //sanity checks
    if(!data_size) return false;

    //91-93   for []
    //123-125 for {}
    if(*data != border) return false;
    if(*(data+data_size-1) != (border+2)) return false;
    --data_size;

    size_t sep1 = 1;
    while( (sep1<data_size)&&(*(data+sep1) != ';')) ++sep1;
    if(sep1==data_size) return false;

    size_t sep2 = sep1+1;
    while( (sep2<data_size)&&(*(data+sep2) != ';')) ++sep2;
    if(sep2>=(data_size-1)) return false;

    out->x = atof(data+1);
    out->y = atof(data+sep1+1);
    out->z = atof(data+sep2+1);

    cerr<<"Cartesian \""<<data<<"\" was read as "<<*out<<endl;
    return true;
}

bool getspherical(const char* data, Vector3D* out)
{
    Vector3D tmp;
    if(!getcartesian(data,&tmp,'[')) return false;

    out->x = tmp.x*sin(tmp.y*M_PI/180)*cos(tmp.z*M_PI/180);
    out->y = tmp.x*sin(tmp.y*M_PI/180)*sin(tmp.z*M_PI/180);
    out->z = tmp.x*cos(tmp.y*M_PI/180);

    cerr<<"Spherical \""<<data<<"\" was read as "<<*out<<endl;
    return true;
}

int main(int argc, char** argv)
{
    if(argc<2)
    {
        cerr<<"select function: sin, square or grav, testcoord\n";
        return 1;
    }

    FuncType type = Func_Sin;
    GravParams gparam;
    void* args = NULL;

    if(strcmp(argv[1],"sin")==0)
    {
        type = Func_Sin;
    }
    else if(strcmp(argv[1],"square")==0)
    {
        type = Func_Square;
    }
    else if(strcmp(argv[1],"grav")==0)
    {
        type = Func_Grav;
        if(argc<5)
        {
            cerr<<"grav mode requires\n\tstart point (i.e. {x0;y0;z0})\n\t"
                  "start velocity (i.e. {vx;vy;vz} or [v;theta;phi])\n\tlinear friction value\n";
            return 1;
        }
        else
        {
            if(!getcartesian(argv[2],&gparam.start))
            {
                cerr<<"Invalid start point "<<argv[2]<<" - use {x0;y0;z0}\n";
                return 1;
            }
            if( (!getcartesian(argv[3],&gparam.speed)) && (!getspherical(argv[3],&gparam.speed)))
            {
                cerr<<"Invalid velocity "<<argv[3]<<" - use {vx;vy;vz} or [v;theta;phi]\n";
                return 1;
            }
            gparam.speed.z = fabs(gparam.speed.z);
            gparam.linear_friction = atof(argv[4]);
        }
        args = &gparam;
    }
    else if(strcmp(argv[1],"testcoord")==0)
    {
        if(argc<3)
        {
            cerr<<"testcoord mode requires a point (i.e. {x;y;z} or [r;theta;phi])";
            return 1;
        }
        if( (!getcartesian(argv[2],&gparam.speed)) && (!getspherical(argv[2],&gparam.speed)))
        {
            cerr<<"Invalid point "<<argv[2]<<"\n";
            return 1;
        }
        cout<<"Test coord "<<argv[2]<<" - success\n";
        return 0;
    }
    else
    {
        cerr<<"invalid function\n";
        return 1;
    }

    try
    {
        calculation(type,args);
    }
    catch(string msg)
    {
        cerr<<"error: "<<msg<<endl;
        return 1;
    }
    return 0;
}
