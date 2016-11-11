#include "pol.h"

const int n_sides= 5;
point2 vertices[n_sides+1];

typedef vec2 point2;

void genPoints() {
	point2 origin = { 0, 0};
	GLfloat pi = (GLfloat)M_PI;
	vertices[0] = origin;
	for( int i = -(pi/2), int k = 1; k <= n_sides; i+= pi/n_sides, ++k) {
		vertices[k].x = sin(i);
		vertices[k].y = cos(i);
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

	glDrawArrays( GL_TRIANGLE_FAN, 0, (n_sides+1));
	glFlush();
}
