#ifndef POVRAY_TEMPLATES_H
#define POVRAY_TEMPLATES_H

#include <iostream>
#include <fstream>

#include <string.h>

namespace povray_templates
{

static const char header[] =
        "#version 3.7;\n"
        "global_settings {assumed_gamma 1.0}\n"
        "#declare viewAngle = clock * 2 * pi;\n"
        "#declare cameraDist = 10;\n"
        "#declare customColor = <1, 1, 0>;\n"
        "#declare csSize = 1;\n\n"
        "camera{\n"
        "location < cos(viewAngle) * cameraDist, 2.5, sin(viewAngle) * cameraDist >\n"
        "angle 50\nlook_at  <0, 1, 0>\n"
        "}\n\n"
        "plane{\n"
        "y, -3\n"
        "pigment{color<1, 1, 1>}\n"
        "}\n\n"
        "light_source {\n"
        "<cos(viewAngle - pi / 4) * cameraDist, 10, sin(viewAngle - pi / 4) * cameraDist>\n"
        "color<1, 1, 1>\n"
        "}\n\n"
        /*"light_source {\n"
        "<cos(viewAngle + pi / 4) * cameraDist, 10, sin(viewAngle + pi / 4) * cameraDist>\n"
        "color<1, 1, 1>\n"
        "}\n\n"*/;

static const char coords[] =
        "cylinder {\n"
        "<-0.3, 0, 0> * csSize\n"
        "< 1.0, 0, 0> * csSize\n"
        "0.01 * csSize\n"
        "pigment{color <1, 0, 0> }\n"
        "}\n\n"
        "cone {\n"
        "< 1.0, 0, 0> * csSize, 0.05 * csSize,\n"
        "< 1.1, 0, 0> * csSize, 0\n"
        "pigment{color <1, 0, 0> }\n"
        "}\n\n"
        "cylinder {\n"
        "<0, 0, -0.3> * csSize\n"
        "<0, 0,  1.0> * csSize\n"
        "0.01 * csSize\n"
        "pigment{color <0, 1, 0>}\n"
        "}\n\n"
        "cone {\n"
        "< 0.0, 0, 1.0> * csSize, 0.05 * csSize,\n"
        "< 0.0, 0, 1.1> * csSize, 0\n"
        "pigment{color <0, 1, 0> }\n"
        "}\n\n"
        "cylinder {\n"
        "<0, -0.3, 0> * csSize\n"
        "<0,  1.0, 0> * csSize\n"
        "0.01 * csSize\n"
        "pigment{color <0, 0, 1>}\n"
        "}\n\n"
        "cone {\n"
        "< 0.0, 1.0, 0> * csSize, 0.05 * csSize,\n"
        "< 0.0, 1.1, 0> * csSize, 0\n"
        "pigment{color <0, 0, 1> }\n"
        "}\n\n"
        "text{\n"
        "ttf \"timrom.ttf\" \"X\"\n"
        "0.1 0\n"
        "pigment{ color <1, 0, 0> }\n\n"
        "scale <1, 1, 1> * csSize / 4\n"
        "translate <1, 0.1, 0> * csSize\n"
        "}\n\n"
        "text{\n"
        "ttf \"timrom.ttf\" \"Y\"\n"
        "0.1 0\n"
        "pigment{ color <0, 1, 0> }\n\n"
        "scale <1, 1, 1> * csSize / 4\n"
        "translate <0, 0.1, 1> * csSize\n"
        "}\n\n"
        "text{\n"
        "ttf \"timrom.ttf\" \"Z\"\n"
        "0.1 0\n"
        "pigment{ color <0, 0, 1> }\n\n"
        "rotate <0, 180, 0>\n"
        "scale <1, 1, 1> * csSize / 4\n"
        "translate <0.25, 1, 0> * csSize\n"
        "}\n";

inline void make_base(const char* filebase,int framecount,double endclock)
{
    char path[256];
    memset(path,0,sizeof(path));
    strcat(path,filebase);
    strcat(path,".ini");
    std::ofstream os;
    os.open(path,std::ofstream::out);
    os<<"Initial_Frame = 1\nFinal_Frame = "<<framecount<<"\n\nInitial_Clock = 0\n"
        "Final_Clock = "<<endclock<<"\n\nInput_File_Name = "<<filebase<<".pov\n"
        "Width=800\nHeight=600\n";
}
}
#endif // POVRAY_TEMPLATES_H
