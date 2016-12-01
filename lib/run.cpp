#include "run.h"

void init() {
	vec2 v[3] = {	vec2( -0.5, -0.5),
					vec2(  0.5, -0.5),
					vec2(  0.0,  0.5) };
	
	divide_line( v[0], v[1], num_iterations);
	divide_line( v[1], v[2], num_iterations);
	divide_line( v[2], v[0], num_iterations);

	startBuffer();
}

void startBuffer() {
	
	GLuint vao, buffer;

	glGenVertexArrays( 1, &vao);
	glBindVertexArray( vao);
	
	glGenBuffers( 1, &buffer);
	glBindBuffer( GL_ARRAY_BUFFER, buffer);
	glBufferData( GL_ARRAY_BUFFER, sizeof( points), points, GL_STATIC_DRAW);

	GLuint program, vPos;
	program = InitShader( "shader.vert", "shader.frag");

	vPos = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( vPos);
	glVertexAttribPointer( vPos, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( 0));

	glClearColor( 0.16, 0.18, 0.18, 1.0);
}

void display() {
	glClear( GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_LINE_STRIP, 0, index);
	glutSwapBuffers();
}
