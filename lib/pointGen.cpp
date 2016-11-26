#include "pointGen.h"

vec2 points[3];
vec2 tmp_p[3];
int w = 512, h = 512;
int c = 0;
GLint windowHeight, windowWidth;

const float DegreesToRadians = M_PI / 180.0;
float angle = 0.001*DegreesToRadians;

void init( bool firstRun) {
	if( firstRun) {
		GLuint vao, buffer;
		glGenVertexArrays( 1, &vao);
		glBindVertexArray( vao);

		glGenBuffers( 1, &buffer);
		glBindBuffer( GL_ARRAY_BUFFER, buffer);
		glBufferData( GL_ARRAY_BUFFER, sizeof(points), NULL, GL_STATIC_DRAW);

		GLuint program = InitShader( "shader.vert", "shader.frag");
		GLuint loc = glGetAttribLocation( program, "vPosition");
		glEnableVertexAttribArray( loc);
		glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

		glClearColor( 0.2, 0.2, 0.2, 1.0);
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
		tmp_p[c].x = (float) x / (w/2) - 1.0;
		tmp_p[c].y = (float) (h-y) / (h/2) - 1.0;
		c++;
	}

	if( c == 3) {
		glutPostRedisplay();
		c = 0;
		points[0] = tmp_p[0];
		points[1] = tmp_p[1];
		points[2] = tmp_p[2];
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
	for( int i = 0; i < 3; ++i) {
		float x = cos( angle) * points[i].x - sin( angle) * points[i].y;
		float y = sin( angle) * points[i].x + cos( angle) * points[i].y;
		points[i].x = x;
		points[i].y = y;
	}
	init( false);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLES, 0, 3);
	glFlush();
}

void idle() {
	glutPostRedisplay();
}
