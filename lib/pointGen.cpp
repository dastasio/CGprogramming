#include "pointGen.h"

const int times_to_subdivide = 5;
const int num_triangles = 729; // 3^5 triangles
const int num_vertices = 3 * num_triangles;
vec2 points[num_vertices];
int Index = 0;

void init() {
	point2 v[3] = { point2(-1.0, -1.0), point2( 0.0, 1.0), point2( 1.0, -1.0)};
	divide_triangle( v[0], v[1], v[2], times_to_subdivide);
	startBuffer();
	display();
}


// ------------------------------------------------------------------------------
//! specifies vertices for a triangle
void triangle( point2 a, point2 b, point2 c) {
	points[ Index++] = a;
	points[ Index++] = b;
	points[ Index++] = c;
}

// ------------------------------------------------------------------------------
//! divides given triangle if k != 0
void divide_triangle( point2 a, point2 b, point2 c, int k) {
	if( k > 0) {
		// calculate midpoints of sides

		point2 ab = ( a + b)/2.0;
		point2 ac = ( a + c)/2.0;
		point2 bc = ( a + c)/2.0;

		// subdivide all triangles but inner

		divide_triangle( a, ab, ac, k-1);
		divide_triangle( c, ac, bc, k-1);
		divide_triangle( b, bc, ab, k-1);
	}
	else triangle( a, b, c); /* draw triangle at end of recursion */
}


// -------------------------------------------------------------------------------
//! sends data to GPU
void startBuffer() {
	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);

	GLuint a_buffer;

	glGenVertexArrays(1, &a_buffer); /* get identifier */
	glBindVertexArray( a_buffer);

	
	GLuint b_buffer;

	glGenBuffers(1, &b_buffer);
	glBindBuffer( GL_ARRAY_BUFFER, b_buffer); /* creates buffer with given id */
	glBufferData( GL_ARRAY_BUFFER, sizeof( points), points, GL_STATIC_DRAW);
				/* allocates memory */

	GLuint loc = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( loc);
	glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

	glClearColor( 0.0, 0.05, 0.1, 1.0); 
}


// -------------------------------------------------------------------------------
//! renders image
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLES, 0, num_triangles);
	glFlush();
}
