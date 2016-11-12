#include "global.h"

int main( int argc, char* argv[]) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_RGBA);
	glutInitWindowSize( 512, 512);
	glutCreateWindow( argv[0]);
	glewInit();

	genPoints();
	sendData();

	glutDisplayFunc( display);
	glutMainLoop();
}
