#ifndef DAVIDE_H
#define DAVIDE_H
#define BUFFER_OFFSET(bytes)  (( GLvoid*) (bytes))
#include "global.h"

static char* readShaderSource( const char* shaderFile);
GLuint InitShader( const char* vShaderFile, const char* fShaderFile);

#endif // DAVIDE_H
