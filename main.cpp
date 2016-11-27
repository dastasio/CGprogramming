#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_RGBA );
	glutInitWindowSize( 700, 700);
	glutInitWindowPosition( 0, 0);
	glutCreateWindow( "OpenGL example");
	glewInit();
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
