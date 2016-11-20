#include "pointGen.h"

const int times_to_subdivide = 5;
const int num_triangles = 729; // 3^5 triangles
const int num_vertices = 3 * num_triangles;
vec3 points[num_vertices];

// ------------------------------------------------------------------------------
//! specifies vertices for a triangle
void triangle( const vec3 &a, const vec3 &b,const vec3 &c) {
	static int Index = 0;
	points[ Index++] = a;
	points[ Index++] = b;
	points[ Index++] = c;
}

// -------------------------------------------------------------------------------
//! draws a tetrahedron

void tetra( vec3 a, vec3 b, vec3 c, vec3 d) {
	triangle( a, b, c);
	triangle( a, c, d);
	triangle( a, d, b);
	triangle( b, d, c);
}

// ------------------------------------------------------------------------------
//! divides a tetrahedron

void divide_tetra( vec3 a, vec3 b, vec3 c, vec3 d, int m) {
	if( m > 0) {
		vec3 mid[6];

		// compute midpoints

		mid[0] = (a + b)/2.0;
		mid[1] = (a + c)/2.0;
		mid[2] = (a + d)/2.0;
		mid[3] = (b + c)/2.0;
		mid[4] = (c + d)/2.0;
		mid[5] = (b + d)/2.0;

		// create tetrahedra

		divide_tetra( a, mid[0], mid[1], mid[2], m-1);
		divide_tetra( mid[0], b, mid[3], mid[5], m-1);
		divide_tetra( mid[1], mid[3], c, mid[4], m-1);
		divide_tetra( mid[2], mid[5], mid[5], d, m-1);
	}
	else tetra( a, b, c, d);
}

// -------------------------------------------------------------------------------
//! renders image
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLES, 0, num_triangles);
	glFlush();
}
