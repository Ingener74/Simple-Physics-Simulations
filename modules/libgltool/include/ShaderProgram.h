/*
 * IShaderProgram.h
 *
 *  Created on: 17.03.2013
 *      Author: pavel
 */

#ifndef ISHADERPROGRAM_H_
#define ISHADERPROGRAM_H_

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glext.h>

#include "IShaderLoader.h"
#include "ErrorLogger.h"

namespace gltools{

class ShaderProgram {
public:
	ShaderProgram( IShaderLoader* shaderLoader );
	virtual ~ShaderProgram();

	virtual void   useProgram(){ glUseProgram(_program); }
	virtual GLuint getProgram(){ return _program; }

	GLuint getAttribute( const char* attr );
	GLuint getUniform( const char* uniform );

	GLuint loadShader( GLenum shaderType, const char* source );
	GLuint createProgram( const char* vertexShader, const char* fragmentShader );

private:
	GLuint _vs;
	GLuint _fs;
	GLuint _program;
};
}


#endif /* ISHADERPROGRAM_H_ */
