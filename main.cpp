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
	glutMainLoop();
}
