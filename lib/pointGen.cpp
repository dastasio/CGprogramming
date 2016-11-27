#include "pointGen.h"

const int times_to_subdivide = 5;
const int num_triangles = 729; // 3^5 triangles
const int num_vertices = 3 * num_triangles;
vec2 points[num_vertices];
int Index = 0;

void init() {
	vec2 v[3] = {
		vec2(-1.0, -1.0), vec2( 0.0, 1.0), vec2( 1.0, -1.0)
	};
	divide_triangle( v[0], v[1], v[2], times_to_subdivide);


	GLuint program = InitShader( "shader.vert", "shader.frag");
	glUseProgram( program);

	GLuint vao;
	glGenVertexArrays(1, &vao); /* get identifier */
	glBindVertexArray( vao);


	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer( GL_ARRAY_BUFFER, buffer); /* creates buffer with given id */
	glBufferData( GL_ARRAY_BUFFER, sizeof( points), points, GL_STATIC_DRAW);
				/* allocates memory */

	GLuint loc = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( loc);
	glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );

	glClearColor( 0.0, 0.05, 0.1, 1.0);

	display();
}


// ------------------------------------------------------------------------------
//! specifies vertices for a triangle
void triangle( const vec2 &a, const vec2 &b,const vec2 &c) {
	points[ Index++] = a;
	points[ Index++] = b;
	points[ Index++] = c;
}

float randomFloat( ) {
	return ( rand() % 70) / 1000.0;
}

// ------------------------------------------------------------------------------
//! divides given triangle if k != 0
void divide_triangle(const vec2 &a, const vec2  &b,const vec2 &c, int k) {
	if( k > 0) {
		// calculate midpoints of sides
		point2 v0 = ( a + b)/2.0;
		point2 v1 = ( a + c)/2.0;
		point2 v2 = ( b + c)/2.0;
		float r = randomFloat();  // random number in range 0 - 0.02
		v0.y += r;
		r = randomFloat();
		v1.y += r;
		r = randomFloat();
		v2.y += r;
		// subdivide all triangles but inner
		divide_triangle( a, v0, v1, k-1);
		divide_triangle( c, v1, v2, k-1);
		divide_triangle( b, v2, v0, k-1);
	}
	else {
		triangle( a, b, c); /* draw triangle at end of recursion */
	}
}


// -------------------------------------------------------------------------------
//! renders image
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for( int i = 0; i < num_vertices; i+= 3) {
		glDrawArrays( GL_LINE_LOOP, i, 3);
	}
	glFlush();
}
