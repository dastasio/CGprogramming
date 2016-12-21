#include "cube.h"

void init() {
	vec3 vert[] = initCube();
}

vec3* initCube() {
	
	vec3 v[] ={ vec3( -1.0, -1.0, -1.0),
				vec3(  1.0, -1.0, -1.0),
				vec3(  1.0,  1.0, -1.0),
				vec3( -1.0,  1.0, -1.0),
				vec3( -1.0, -1.0,  1.0),
				vec3(  1.0, -1.0,  1.0),
				vec3(  1.0,  1.0,  1.0),
				vec3( -1.0,  1.0,  1.0) };
	
	return v;
}
