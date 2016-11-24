#include "pointGen.h"

const int NumPoints = 10000;
typedef vec2 point2;
typedef vec3 point3;

void init() {
	point3 points[NumPoints];

	// triangle in plane z = 0

	point3 vertices[4]= { point3(  0.0,  0.0,  1.0), 
						  point3(  1.0, -1.0, -1.0), 
						  point3(  0.0,  1.0, -1.0),
						  point3(  0.0,  0.0,  1.0) };

	points[0] = point3( 0.0, 0.0, 0.0);

	for( int k = 1; k < NumPoints; ++k) {
		int j = rand() % 4; // pick random vertex

		// calculate halfway point between vertex and previous point
		points[k] = ( points[k-1] + vertices[j] )/2.0;
	}
 

	GLuint abuffer; // Starting generation of vertex-array object

	glGenVertexArrays(1, &abuffer); // generate unused identifier
	glBindVertexArray(abuffer);


	GLuint buffer;  // Generation of buffer object on GPU

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);				 // creates buffer with identifier
										   				 //! from glGenBuffers
	glBufferData(GL_ARRAY_BUFFER, sizeof(points),
				points, GL_STATIC_DRAW);  // allocates GPU memory for our data


	// glClearColor(1.0, 1.0, 1.0, 1.0);
	// glPointSize(2.0);
}


void display() {
	glClear( GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_POINTS, 0, NumPoints);
	glFlush();
}
