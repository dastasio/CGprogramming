#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize( 500, 500);
	glutInitWindowPosition( 0, 0);
	glutCreateWindow( "OpenGL example");
	glewInit();
	glutDisplayFunc(display);
	init();

	GLuint program;
	program = InitShader( "vshader.glsl", "fshader.glsl");

	GLuint loc;
	loc = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glutMainLoop();
}
