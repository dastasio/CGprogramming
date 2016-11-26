#include "pointGen.h"

vec2 points[3];
int w = 512, h = 512;
int c = 0;
GLint windowHeight, windowWidth;

void init( bool firstRun) {
	if( firstRun) {
		GLuint vao, buffer;
		glGenVertexArrays( 1, &vao);
		glBindVertexArray( vao);

		glGenBuffers( 1, &buffer);
		glBindBuffer( GL_ARRAY_BUFFER, buffer);
		glBufferData( GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STATIC_DRAW);

		GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
		GLuint loc = glGetAttribLocation( program, "vPosition");
		glEnableVertexAttribArray( loc);
		glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	}
	else {
		glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);
	}
}


void mouse( int button, int state, int x, int y) {
	if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		exit(0);
	}

	if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		points[c].x = (float) x / (w/2) - 1.0;
		points[c].y = (float) (h-y) / (h/2) - 1.0;
		c++;
	}

	if( c == 3) {
		init( false);
		glutPostRedisplay();
		c = 0;
	}
}

void reshape( GLsizei w, GLsizei h) {
	windowWidth = w;
	windowHeight = h;
	glViewport( 0, 0, windowWidth, windowHeight);
}

// -------------------------------------------------------------------------------
//! renders image
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLES, 0, 3);
	glFlush();
}
