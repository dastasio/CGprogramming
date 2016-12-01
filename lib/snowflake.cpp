#include "snowflake.h"

vec2 points[num_points];

const float theta = 120 * degreesToRadians;	// constant angle of 120 degrees

int index = 0;

/* divides a line into 4 */
void divide_line( vec2 &a, vec2 &b, int iterCount) {
	if( iterCount > 0) {
		float angle = find_angle( a, b) + theta;
		float dist = find_length( a, b) / 3;
		
		vec2 v0 = ( b - a)/3 + a;
		vec2 v1 = ( a - b)/3 + b;
		vec2 v2 = move_point( v0, dist, angle);
		
		printf( "div_line:  a:\t%f,\t%f\n", a.x, a.y);
		printf( "div_line:  b:\t%f,\t%f\n", b.x, b.y);
		printf( "div_line: v0:\t%f,\t%f\n", v0.x, v0.y);
		printf( "div_line: v1:\t%f,\t%f\n", v1.x, v1.y);
		printf( "div_line: v2:\t%f,\t%f\n", v2.x, v2.y);
		divide_line(  a, v0, iterCount - 1);
		divide_line( v0, v2, iterCount - 1);
		divide_line( v2, v1, iterCount - 1);
		divide_line( v1,  b, iterCount - 1);
	}
	else {
		store_point( a);
		printf( "div_line: Stored a =\t%f,\t%f\n", a.x, a.y);
		store_point( b);
		printf( "div_line: Stored b =\t%f,\t%f\n", b.x, b.y);
	}
}



/* returns distance between points a and b */
float find_length( vec2 &a, vec2 &b) {
	float root = pow( ( b.x - a.x), 2) + pow( ( b.y - a.y), 2);
	return sqrt( root);
}



/* finds angle of a line, given its vertices */
float find_angle( vec2 &a, vec2 &b) {
	if( a.x == b.x) {
		if( a.y > b.y)
			return ( M_PI / 2);
		else
			return 3 * ( M_PI / 2);
	}
	else if( a.y == b.y) {
		if( a.x > b.x)
			return 0;
		else
			return M_PI;
	}
	else {
		vec2 tmp = b - a;
		return asin( tmp.y / find_length( a, b));
	}
}



/* moves by one at a given angle, starting at given point */
vec2 move_point( vec2 &a, float dist, float angle) {
	float x = a.x + ( dist * cos( angle));
	float y = a.y + ( dist * sin( angle));
	return vec2( x, y);
}



/* checks if given point already exists,
	if not: stores it in gloabl array */
void store_point( vec2 &v) {
	if( index > 0 && ( points[index-1].x != v.x || points[index-1].y != v.y) ) {
		printf( "store_point: v%d:\t%f,\t%f\tc1\n", index, v.x, v.y);
		points[index++] = v;
	}
	/*if( index > 0 && points[index-1] != v) {
		points[index++] = v;
	}*/
	else if( index == 0) {
		printf( "store_point: v%d:\t%f,\t%f\tc2\n", index, v.x, v.y);
		points[index++] = v;
	}
}
