#ifndef POINTGEN_H
#define POINTGEN_H
#include "global.h"

extern int c, w, h;

void init( bool);
void mouse( int button, int state, int x, int y);
void display();
void idle();
void demo_menu( int id);

#endif // POINTGEN_H
