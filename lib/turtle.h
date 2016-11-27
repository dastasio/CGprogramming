#ifndef TURTLE_H
#define TURTLE_H
#include "global.h"

#define TOTAL_LENGTH 0

class dTurtle {
public:
	
	dTurtle();
	
	/* initializes turtle */
	void turtle_init( float x, float y, float theta);

	/* moves forward by given distance */
	void forward( float dist);

	/* turns l/r by given angle */
	void right( float angle);
	void left( float angle);

	/* toggles pen state */
	void pen( bool down);

	void render();

	vec2 t_positions[500];
private:
	/* current angle of turtle */
	float t_theta;
	
	/* current position of turtle */
	float t_x, t_y;

	/* current state of turtle's pen */
	bool t_penDown;

	/* number of turtle written positions */
	int t_posCount;
};

#endif // TURTLE_H
