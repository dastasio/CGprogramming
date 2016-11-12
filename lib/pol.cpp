#include "pol.h"
typedef vec2 point2;

const int n_sides= 5;
point2 vertices[n_sides+1];

void genPoints() {
	vertices[0] = point2( 0, 0);
	for( int i = -(M_PI/2), k = 1; k <= n_sides; i+= M_PI/n_sides, ++k) {
	}
}

void sendData() {
	/* generating Vertex Array Object */
	GLuint vao;

	glGenVertexArrays( 1, &vao);
	glBindVertexArray( vao);
	
	/* creating buffer object */
	GLuint buffer;

	glGenBuffers( 1, &buffer);
	glBindBuffer( GL_ARRAY_BUFFER, buffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);

	glClearColor( 0.0, 0.0, 0.0, 1.0);
}

void display() {
	glClear( GL_COLOR_BUFFER_BIT);

	glDrawArrays( GL_TRIANGLE_FAN, 0, n_sides);
	glFlush();
}
