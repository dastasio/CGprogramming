#include "pointGen.h"

typedef vec2 point2;

void init() {
	const int NumPoints = 5000;
	point2 points[NumPoints];

	// triangle in plane z = 0

	point2 vertices[3]= {point2(-1.0, -1.0), point2(0.0, 1.0), point2(1.0, -1.0)};

	points[0] = point2( 0.25, 0.50);

	for( int k = 1; k < NumPoints; ++k) {
		int j = rand() % 3; // pick random vertex

		// calculate halfway point between vertex and previous point
		points[k] = ( points[k-1]+vertices[j])/2.0;
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

	// SPHERE
	
	/*const float DegreesToRadians = M_PI / 180.0;

	point3 quad_data[342];  // 8 rows of 18 quads

	int k = 0;
	for( float phi = -80.0; phi <= 80.0; phi += 20.00) {
		float phir = phi*DegreesToRadians;
		float phir20 = (phi + 20.0)*DegreesToRadians;

		for( float theta = -180.0; theta <= 180.0; theta += 20.0) {
			float thetar = theta*DegreesToRadians;
			quad_data[k] = point3( sin(thetar)*cos(phir), cos(thetar)*cos(phir),
									sin(phir));

			k++;
			quad_data[k] = point3(sin(thetar)*cos(phir20), cos(thetar)*cos(phir20),
									sin(phir20));
			k++;
		}
	}

	k = 0;
	point3 strip_data[40];

	strip_data[k] = point3( 0.0, 0.0, 1.0);
	k++;

	float sin80 = sin(80.0*DegreesToRadians);
	float cos80 = cos(80.0*DegreesToRadians);

	for(float theta = -180.0; theta <= 180.0; theta += 20.0) {
		float thetar = theta*DegreesToRadians;
		strip_data[k] = point3(sin(thetar)*cos80, cos(thetar)*cos80, sin80);

		k++;
	}

	strip_data[k] = point3(0.0, 0.0, -1.0);
	k++;

	for( float theta = -180.0; theta <= 180.0; theta += 20.0) {
		float thetar = theta;
		strip_data[k] = point3( sin(thetar)*cos80,cos(thetar)*cos80, sin80);

		k++;
	}

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glPointSize(2.0); */
}


void display() {
	glClear( GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_POINTS, 0, 500);
	glFlush();
}
