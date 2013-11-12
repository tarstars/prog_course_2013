#version 3.7;
global_settings {assumed_gamma 1.0}

camera {
	location <0, 10, 0>
	look_at<0, 0, 0>
}

light_source {
	<0, 0, 10> //position
	color<1, 1, 1>
}

//#include "scene.pov"

sphere {
	<0, 0, 0> //position of center
	1 //radius
	pigment {
		color <1, 0, 0>
	}
}

sphere {
	<0, 0, 1> //position of center
	0.5 //radius
	pigment {
		color <0, 1, 0>
	}
}

cylinder {
	<0, 0, 0> //center of one circle
	<0, 1.5, 0> //center of another circle
	0.5 //distance between centers
	pigment {
		color <1, 1, 0>
	}
}

