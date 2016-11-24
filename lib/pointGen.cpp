#include "pointGen.h"
typedef vec3 color3;
typedef vec3 point3;

const int n_sub = 4;
const int num_tetrahedra = 256;
const int num_triangles = 4 * num_tetrahedra; // 3^5 triangles
const int num_vertices = 3 * num_triangles;
int colorindex;
vec3 points[num_vertices];
color3 colors[num_vertices];
color3 base_colors[4] = {color3(1.0, 0.0, 0.0), color3(0.0, 1.0, 0.0),
						 color3(0.0, 0.0, 1.0), color3(0.0, 0.0, 0.0)};


// ------------------------------------------------------------------------------
//! init

void init() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray( vao);

	vec3 v[4] = {
	vec3(  0.0,  0.0, -1.0 ),
	vec3(  0.0,  1.0,  0.0 ),
	vec3( -1.0, -1.0,  0.0 ),
	vec3(  1.0, -1.0,  0.0 ) 
    };	

	divide_tetra( v[0], v[1], v[2], v[3], n_sub);

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer( GL_ARRAY_BUFFER, buffer);

	// allocating uninitialized data
	glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors),
				 NULL, GL_STATIC_DRAW);
	
	// loading separate arrays of data
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
	
	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);

	GLuint loc, loc2;
	loc = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( loc);
	glVertexAttribPointer( loc, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	loc2 = glGetAttribLocation( program, "vColor");
	glEnableVertexAttribArray( loc2);
	glVertexAttribPointer( loc2, 3, GL_FLOAT, GL_FALSE, 0,
						   BUFFER_OFFSET( sizeof( points)));

	glEnable( GL_DEPTH_TEST);
	glClearColor(0.1, 0.1, 0.1, 1.0);
}

// ------------------------------------------------------------------------------
//! specifies vertices for a triangle
void triangle( const vec3 &a, const vec3 &b,const vec3 &c, const int color) {
	static int Index = 0;
	colors[ Index] = base_colors[color];
	points[ Index++] = a;
	colors[ Index] = base_colors[color];
	points[ Index++] = b;
	colors[ Index] = base_colors[color];
	points[ Index++] = c;
}

// -------------------------------------------------------------------------------
//! draws a tetrahedron
void tetra( vec3 a, vec3 b, vec3 c, vec3 d) {
	triangle( a, b, c, 0);
	triangle( a, c, d, 1);
	triangle( a, d, b, 2);
	triangle( b, d, c, 3);
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
		divide_tetra( mid[2], mid[4], mid[5], d, m-1);
	}
	else tetra( a, b, c, d);
}

// -------------------------------------------------------------------------------
//! renders image
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glDrawArrays( GL_TRIANGLES, 0, num_triangles);
	glFlush();
}
