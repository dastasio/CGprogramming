#include "global.h"

int main( int argc, char** argv) {
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize( w, h);
	glutCreateWindow( "OpenGL example");

	glewInit();
	init( true);

	glutCreateMenu(demo_menu);
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("start rotation", 2);
	glutAddMenuEntry("stop rotation", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc( idle);
	glutMainLoop();
}
