#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 512, 512);
	glutCreateWindow( "OpenGL example");

	glewInit();
	init();

	glutDisplayFunc(display);
	glutMainLoop();
}
