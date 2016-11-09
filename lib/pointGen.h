#ifndef POINTGEN_H
#define POINTGEN_H
#include "global.h"

extern const int times_to_subdivide;
extern const int num_triangles;
extern const int num_vertices;

typedef vec2 point2;

void init();
void triangle( point2 a, point2 b, point2 c);
void divide_triangle( point2 a, point2 b, point2 c, int k);
void startBuffer();
void display();

#endif // POINTGEN_H
