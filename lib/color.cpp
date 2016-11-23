#include "color.h"

void init() {
	
	vec2 v[3] = {	vec2( -0.75, -0.75),
					vec2(  0.75, -0.75),
					vec2(  0.0,  0.75) };
	
	vec3 c[3] = {	vec3( 1.0, 0.0, 0.0),
					vec3( 0.0, 1.0, 0.0),
					vec3( 0.0, 0.0, 1.0) };
	
	GLuint vao;
	glGenVertexArrays( 1, &vao);
	glBindVertexArray( vao);

	GLuint buf;
	glGenBuffers( 1, &buf);
	glBindBuffer( GL_ARRAY_BUFFER, buf);
	glBufferData( GL_ARRAY_BUFFER, sizeof(v) + sizeof(c), NULL, GL_STATIC_DRAW);

	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(v), v);
	glBufferSubData( GL_ARRAY_BUFFER, sizeof(v), sizeof(c), c);

	GLuint program = InitShader( "vshader.glsl", "fshader.glsl");
	glUseProgram( program);

	GLuint loc_vertex, loc_color;
	loc_vertex = glGetAttribLocation( program, "vPosition");
	glEnableVertexAttribArray( loc_vertex);
	glVertexAttribPointer( loc_vertex, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	loc_color = glGetAttribLocation( program, "vColor");
	glEnableVertexAttribArray( loc_color);
	glVertexAttribPointer( loc_color, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof(v)));

}

void display() {
	glClear( GL_COLOR_BUFFER_BIT);
	glDrawArrays( GL_TRIANGLES, 0, 3);
	glFlush();
}
