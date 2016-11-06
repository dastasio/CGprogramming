#ifndef VEC_H
#define VEC_H
#include "global.h"

struct vec2 {
	GLfloat x;
	GLfloat y;
	
	// if no parameters are given, set x and y to 0.0
	vec2( GLfloat s = GLfloat(0.0)) :
		x(s), y(s) {}
	
	// if params are given, set x and y accordingly
	vec2( GLfloat tmpX, GLfloat tmpY) :
		x(tmpX), y(tmpY) {}

	// if a vector is given, transfer its values to x and y
	vec2( const vec2& v)
		{ x = v.x; y = v.y;}
	
	GLfloat& operator [] ( int i) { return *(&x + i); }
	const GLfloat operator [] ( int i) const { return *(&x + i); }

	// operations defining
	vec2 operator - () const
		{ return vec2( -x, -y); }

	vec2 operator + ( const vec2& v) const
		{ return vec2( x + v.x, y + v.y); }
	
	vec2 operator - ( const vec2& v) const
		{ return vec2( x - v.x, y - v.y); }

	vec2 operator * ( const GLfloat s) const
		{ return vec2( x*s, y*s); }

	vec2 operator * ( const vec2& v) const
		{ return vec2( x * v.x, y * v.y); }
	
	vec2 operator / ( const GLfloat s) const {
#ifdef DEBUG
		if( std::fabs(s) < DivideByZeroTolerance ) {
			std::cerr << "[" << __FILE__ << ";" << __LINE__ << "] "
					  << "Division by zero" << std::endl;
			return vec2();
		}
#endif // DEBUG

		GLfloat r = GLfloat( 1.0) / s;
		return *this * s;
	}



	vec2 operator += ( const vec2& v)
		{ return vec2( x += v.x, y += v.y); }
	
	vec2 operator -= ( const vec2& v)
		{ return vec2( x -= v.x, y -= v.y); }
	
	vec2 operator *= ( const GLfloat s)
		{ return vec2( x *= s, y *= s); }
	
	vec2 operator *= ( const vec2& v) 
		{ return vec2( x *= v.x, x *= v.y); }

	vec2 operator /= ( const GLfloat s) {
#ifdef DEBUG
		if( std::fabs(s) < DivideByZeroTolerance) {
			std::cerr << "[" << __FILE__ << ";" << __LINE__ << "] "
					  << "Division by zero" << std::endl;
			return vec2();
		}
#endif // DEBUG
		
		GLfloat r = GLfloat(1.0) / s;
		*this *= r;

		return *this;
	}
};


#endif // VEC_H
