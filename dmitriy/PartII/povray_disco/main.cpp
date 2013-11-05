#include <iostream>
#include <fstream>

#include <math.h>

#define FILEBASE "disco"

using namespace std;

static const char head[] =
"#version 3.7;\n"
"global_settings {assumed_gamma 1.0}\n"
"#include \"colors.inc\"\n"
"#include \"shapes.inc\"\n#include \"textures.inc\"\n"
"#include \"glass.inc\"\n#include \"metals.inc\"\n#include \"stones.inc\"\n"
"#include \"finish.inc\"\n"
"camera {\n"
//"    location <10*sin(2*pi*clock/5),1,10*cos(2*pi*clock/5)>\n"
"    location <1,3,12>\n"
"    look_at<0,0,0>\n"
"}\n"
"#declare Lightbulb = union {\n"
"    merge {\n"
"      sphere { <0,0,0>,1 }\n"
"      cylinder {\n"
"        <0,5,0>, <0,0,0>, 0.25\n"
"      }\n"
"      texture {\n"
"        pigment {color<cos(2*pi*clock)*cos(2*pi*clock),cos(2*pi*clock)*(1-cos(2*pi*clock)),1-cos(2*pi*clock)>}\n"
"        finish {ambient .8 diffuse .6}\n"
"      }\n"
"      hollow on\n"
"    }\n"
"    cylinder {\n"
"      <0,5,1>, <0,1.1,0>, 0.3\n"
"      texture { Brass_Texture }\n"
"    }\n"
"  }\n"
"light_source {\n"
"    <0,0,0>\n"
"    color<cos(2*pi*clock)*cos(2*pi*clock),cos(2*pi*clock)*(1-cos(2*pi*clock)),1-cos(2*pi*clock)>\n"
"    looks_like{Lightbulb}\n"
"    translate<0,4,0>\n"
"}\n"

"plane{\n"
"   y, -3\n"
"   pigment{color<0.5,0.5,0.5>}\n"
"}\n";
/*
"#include \"stars.inc\"\n"
"sphere{ <0,0,0>, 1\n"
"        texture{ Starfield2 scale 0.25}\n"
"        scale 10000\n"
"      }\n";*/

static const char inifile[] =
"Initial_Frame = 1\n"
"Final_Frame = 100\n"
"Initial_Clock = 0\n"
"Final_Clock = 5\n"
"Input_File_Name = "FILEBASE".pov\n"
"Width=800\n"
"Height=600\n";

int main(void)
{
    ofstream os;
    os.open(FILEBASE".pov",ofstream::out);
    os<<head<<endl<<endl;
    
    os<<"#declare ClockStart=0;\n#declare ClockDuration=5;\n\n";
    
    os<<
"#declare StickManHand = union {\n"
"sphere{\n"
"    <0,1,0>\n"
"    0.4\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <0,-1,0>\n"
"    <0,1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <-1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n";
    for(double d = -1; d <= 1; d+=0.05)
    {
        os<<"sphere{\n"
            "    <"<<d<<",0.5*sin(2*pi*(clock-ClockStart)/ClockDuration)*sin(pi*"<<d<<"/2),0>\n"
            "    0.08\n"
            "    pigment{\n"
            "        color<1,1,1>\n"
            "    }\n"
            "}\n";
    }
    os<<"\n\n};\n\n";
////////////////////////////////
    
    os<<"#declare StickManHead = union {\n"
"sphere{\n"
"    <0.2*sin(2*pi*(clock-ClockStart)/ClockDuration),1,0>\n"
"    0.4\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <0,-1,0>\n"
"    <0,0,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n";

    for(double d = 0; d <= 1; d+=0.01)
    {
        os<<"sphere{\n"
            "    <0.2*sin(2*pi*(clock-ClockStart)/ClockDuration)*sin(pi*"<<d<<"/2),"<<d<<",0>\n"
            "    0.08\n"
            "    pigment{\n"
            "        color<1,1,1>\n"
            "    }\n"
            "}\n";
    }

    os<<
"cylinder {\n"
"    <-1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <-1,0.5*sin(2*pi*(clock-ClockStart)/ClockDuration),0>\n"
"    <1,-0.5*sin(2*pi*(clock-ClockStart)/ClockDuration),0>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n\n};\n\n";
    
////////////////////////////////
    os<<"#declare StickManStat = union {\n"
"sphere{\n"
"    <0,1,0>\n"
"    0.4\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <0,-1,0>\n"
"    <0,1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <-1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <-1,0,0>\n"
"    <1,0,0>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n\n};\n\n";

////////////////////////////////
    os<<"#declare StickManBall = union {\n"
"sphere{\n"
"    <0,1,0>\n"
"    0.4\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"    translate<sin(2*pi*(clock-ClockStart)/ClockDuration),0,"
     "sin(2*pi*(clock-ClockStart)/ClockDuration)*sin(2*pi*(clock-ClockStart)/ClockDuration)>\n"
"}\n"
"cylinder {\n"
"    <0,-1,0>\n"
"    <0,0.5,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <-1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
"cylinder {\n"
"    <1,-1.5,0>\n"
"    <0,-1,0,>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n";
/*
"cylinder {\n"
"    <-1,0,0>\n"
"    <1,0,0>\n"
"    0.1\n"
"    pigment{\n"
"        color<1,1,1>\n"
"    }\n"
"}\n"
*/
    for(double d = -1; d <= 1; d+=0.01)
    {
        os<<"sphere{\n"
            "    <sin(2*pi*("<<d<<"+1)/2),0.5,sin(2*pi*("<<d<<"+1)/2)*sin(2*pi*("<<d<<"+1)/2)>\n"
            "    0.08\n"
            "    pigment{\n"
            "        color<1,1,1>\n"
            "    }\n"
            "}\n";
    }
    os<<
"};\n\n";

////////////////////////////////////

    os<<"object{ StickManHand translate<3,-1.5,0>}\n"
        "object{ StickManStat rotate<180,0,0> rotate<0,(clock-ClockStart)*360/ClockDuration> translate<-3,-1.5,0>}\n"
        "object{ StickManHead translate<0.5,-1.5,-2.7>}\n"
        "object{ StickManBall translate<0.5,-1.5,2.7>}\n";
    
    os.close();
    
    //////////////////////////////
    ofstream osini;
    osini.open(FILEBASE".ini",ofstream::out);
    osini<<inifile;
    osini.close();

    return 0;
}
