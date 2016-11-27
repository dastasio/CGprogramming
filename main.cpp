#include "global.h"

int main( int argc, char* argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize( 700, 700);
	glutCreateWindow( "Turtle Program");

	glewInit();
	
	glutMainLoop();
}
