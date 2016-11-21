#ifndef POINTGEN_H
#define POINTGEN_H
#include "global.h"

extern const int n_sub;
extern const int num_triangles;
extern const int num_vertices;

void init();
void triangle( const vec3 &a, const vec3 &b,const vec3 &c);
void tetra( vec3 a, vec3 b, vec3 c, vec3 d);
void divide_tetra( vec3 a, vec3 b, vec3 c, vec3 d, int m);
void display();

#endif // POINTGEN_H
