#include "pol.h"
typedef vec2 point2;

const int n_sides = 5;
point2 vertices[n_sides+2];
GLuint vao, buffer;

void genPoints() {
	vertices[0] = point2( 0, 0);
	float curr_angle, delta_angle;
	curr_angle = M_PI/2;
	for( int i = 1; i <= n_sides; ++i) {
		vertices[i] = point2( cos(curr_angle), sin(curr_angle));
		delta_angle = 2 * i * ( (M_PI) / n_sides);
		curr_angle = ( M_PI/2) + delta_angle;
	}
	vertices[ n_sides + 1] = point2( cos( M_PI/2), sin( M_PI/2));
}

void sendData() {
	/* generating Vertex Array Object */

	glGenVertexArrays( 1, &vao);
	glBindVertexArray( vao);

	genPoints();
	
	/* creating buffer object */

	glGenBuffers( 1, &buffer);
	glBindBuffer( GL_ARRAY_BUFFER, buffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);

	glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray( 0);
	glClearColor( 0.3, 0.3, 0.3, 1.0);
}

void display() {
	glClear( GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLE_FAN, 0, (n_sides+2));
	glFlush();
}
