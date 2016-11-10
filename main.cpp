#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_RGBA);
	glutInitWindowSize( 512, 512);
	glutCreateWindow( argv[0]);

	if( glewInit()) {
		std::cerr << "Unable to initalize GLEW ... exiting" << std::endl;
		exit( EXIT_FAILURE);
	}

	init();

	glutDisplayFunc( display);

	glutMainLoop();
}
