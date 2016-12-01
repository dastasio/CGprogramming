#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H
#include "global.h"

const int num_iterations = 2;
const int num_lines = 4 * 4;	// 4^(3-1)
const int num_points = num_lines;
extern vec2 points[num_points];

extern const float theta;
extern int index;

void divide_line( vec2 &a, vec2 &b, int iterCount);
float find_length( vec2 &a, vec2 &b);
float find_angle( vec2 &a, vec2 &b);
vec2 move_point( vec2 &a, float dist, float angle);
void store_point( vec2 &v);

#endif // SNOWFLAKE_H
