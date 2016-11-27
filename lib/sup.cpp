#include "sup.h"

void renderTurtle( (vec2&) [] data, int count) {
	glBufferSubData( GL_VERTEX_BUFFER, 0, sizeof(data), data);
	glutPostRedisplay();
}

void init() {
	
	dTurtle m_turtle = new dTurtle();

	GLuint vao, buffer;

	glGenVertexArrays( 1, &vao);
	glBindVertexArray( vao);
	
	vec2 tmp[1000];
	glGenBuffers( 1, &buffer);
	glBindBuffer( GL_VERTEX_BUFFER, buffer);
	glBufferData( GL_VERTEX_BUFFER, sizeof(tmp), NULL, GL_DYNAMIC_DRAW);

	GLuint program = InitShader( "shader.vert", "shader.frag");

	GLuint loc = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( loc);
	glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}
