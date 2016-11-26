#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize( w, h);
	glutCreateWindow( "OpenGL example");

	glewInit();
	init( true);

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc( idle);
	glutMainLoop();
}
