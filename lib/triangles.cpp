#include "triangles.h"

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

// --------------------------------------------------------------------------------
//! init

void init() {
	glGenVertexArrays( NumVAOs, VAOs);
	glBindVertexArray( VAOs[Triangles]);

	GLfloat vertices[NumVertices] [2] = {
		{ -0.90, -0.90 },  // Triangle 1
		{  0.85, -0.90 },
		{ -0.90,  0.85 },
		{  0.90, -0.85 },  // Triangle 2
		{  0.90,  0.90 },
		{ -0.85,  0.90 }
	};

	glGenBuffers( NumBuffers, Buffers);
	glBindBuffer( GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);
	
	glVertexAttribPointer( vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray( vPosition);
}

// --------------------------------------------------------------------------------
//! display

void display() {
	glClear( GL_COLOR_BUFFER_BIT);

	glBindVertexArray( VAOs[Triangles]);
	glDrawArrays( GL_TRIANGLES, 0, NumVertices);

	glFlush();
}