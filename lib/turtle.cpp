#include "turtle.cpp"

dTurtle::dTurtle() {
	t_theta = 0;
	t_x = 0;
	t_y = 0;
	t_penDown = false;

	t_posCount = 0;
}

// TURTLE INIT FUNCTION ---------------------------------------------------------------------------------------------------
void dTurtle::turtle_init( float x, float y, float theta) {
	
	t_theta = theta * dToRadians;

	t_x = x;
	t_y = y;
}

// TURTLE MOVE FUNCTION ---------------------------------------------------------------------------------------------------
void dTurtle::forward( float dist) {
	
	t_x = dist * cos( t_theta);
	t_x = dist * sin( t_theta);

	if( t_penDown) {
		t_positions [t_posCount++] = vec2( t_x, t_y);
	}
}

// TURTLE PEN DOWN FUNCTION ----------------------------------------------------------------------------------------------
void dTurtle:pen( bool down) {
	
	switch( t_penDown) {
	case true:
		t_penDown = down;
		break;

	case false:
		if( down) {
			t_positions [t_posCount++] = vec2( t_x, t_y);
			t_penDown = true;
		}
		break;
	}
}


// TURN RIGHT FUNCTION --------------------------------------------------------------------------------------------------
void dTurtle::right( float angle) {
	t_theta -= angle * dToRadians;
}

// TURN LEFT FUNCTION ---------------------------------------------------------------------------------------------------
void dTurtle::left( float angle) {
	t_theta += angle * dToRadians;
}

// TURTLE RENDER FUNCTION -----------------------------------------------------------------------------------------------
void dTurtle::render() {
	vec2 tmp_array[t_posCount];

	for( int i = 0; i <= t_posCount; i++) {
		tmp_array.x = t_positions[i].x;
		tmp_array.y = t_positions[i].y;
	}

	renderTurtle( tmp_array, t_posCount + 1);
	t_posCount = 0;
}
