#version 3.7;

global_settings {assumed_gamma 1.0}

#declare dist = 10;

camera {
  location <dist * cos(2 * pi * clock), 7, dist * sin( 2 * pi * clock)>
  look_at <0, 0, 0>
  angle 30
}

light_source {
  <5, 10, 5>
  color <1, 1, 1>
}
sphere{ <0, 0, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 0, 1> .1 pigment {color<1,1,1>}}
sphere{ <0, -1, 0> .1 pigment {color<1,1,1>}}
sphere{ <1, 0, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 1, 0> .1 pigment {color<1,1,1>}}
sphere{ <-1, 0, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 0, -1> .1 pigment {color<1,1,1>}}
sphere{ <-1, 0, -1> .1 pigment {color<1,1,1>}}
sphere{ <0, 1, 1> .1 pigment {color<1,1,1>}}
sphere{ <0, -1, 1> .1 pigment {color<1,1,1>}}
sphere{ <-1, 0, 1> .1 pigment {color<1,1,1>}}
sphere{ <-1, 1, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 1, -1> .1 pigment {color<1,1,1>}}
sphere{ <0, -1, -1> .1 pigment {color<1,1,1>}}
sphere{ <1, 0, 1> .1 pigment {color<1,1,1>}}
sphere{ <-1, -1, 0> .1 pigment {color<1,1,1>}}
sphere{ <1, 1, 0> .1 pigment {color<1,1,1>}}
sphere{ <1, -1, 0> .1 pigment {color<1,1,1>}}
sphere{ <1, 0, -1> .1 pigment {color<1,1,1>}}
sphere{ <1, -1, 1> .1 pigment {color<1,1,1>}}
sphere{ <1, 1, 1> .1 pigment {color<1,1,1>}}
sphere{ <-1, -1, -1> .1 pigment {color<1,1,1>}}
sphere{ <-1, 1, 1> .1 pigment {color<1,1,1>}}
sphere{ <-1, 1, -1> .1 pigment {color<1,1,1>}}
sphere{ <1, -1, -1> .1 pigment {color<1,1,1>}}
sphere{ <1, 1, -1> .1 pigment {color<1,1,1>}}
sphere{ <-1, -1, 1> .1 pigment {color<1,1,1>}}
sphere{ <0, -2, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 0, -2> .1 pigment {color<1,1,1>}}
sphere{ <2, 0, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 2, 0> .1 pigment {color<1,1,1>}}
sphere{ <0, 0, 2> .1 pigment {color<1,1,1>}}
sphere{ <-2, 0, 0> .1 pigment {color<1,1,1>}}
