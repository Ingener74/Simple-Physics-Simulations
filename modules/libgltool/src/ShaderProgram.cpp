/*
 * IShaderProgram.cpp
 *
 *  Created on: 17.03.2013
 *      Author: pavel
 */

#include "ShaderProgram.h"

namespace gltools{

ShaderProgram::ShaderProgram( IShaderLoader* sl ){

	_program = createProgram(sl->getVertexSource(), sl->getFragmentSource());
	if(!_program){
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "error: could not create program");
	}
}

GLuint ShaderProgram::getAttribute( const char* attr ){
	return glGetAttribLocation(_program, attr);
}

GLuint ShaderProgram::getUniform( const char* uniform ){
	return glGetUniformLocation(_program, uniform);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(_program);
	glDeleteShader(_vs);
	glDeleteShader(_fs);
}

GLuint ShaderProgram::loadShader( GLenum shaderType, const char* source ){

	GLuint shader = glCreateShader(shaderType);
	if(shader){
		glShaderSource(shader, 1, &source, 0);
		glCompileShader(shader);

		GLint compiled = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if(!compiled){
			GLint infoLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
			if(infoLen){
				char* buf = new char[infoLen];
				if(buf){
					glGetShaderInfoLog(shader, infoLen, 0, buf);
					ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "Could not compile shader: %d,\n%s", shaderType, buf);
					delete buf;
				}
				glDeleteShader(shader);
				shader = 0;
			}
		}
	}
	return shader;
}

GLuint ShaderProgram::createProgram( const char* vertexShader, const char* fragmentShader ){

	_vs = loadShader(GL_VERTEX_SHADER, vertexShader);
	if(!_vs){
		return 0;
	}
	_fs = loadShader(GL_FRAGMENT_SHADER, fragmentShader);
	if(!_fs){
		return 0;
	}

	GLuint program = glCreateProgram();
	if(program){
		glAttachShader(program, _vs);
		glAttachShader(program, _fs);

		glLinkProgram(program);
		GLint linkStatus = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
		if(linkStatus == GL_FALSE){
			GLint bufLen = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLen);
			if(bufLen){
				char* buf = (char*)new char[bufLen];
				if(buf){
					glGetProgramInfoLog(program, bufLen, NULL, buf);
					ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "Shader program error", "%s", buf);
					delete [] buf;
				}
			}
			glDeleteProgram(program);
			program = 0;
		}
	}else{
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "error: program could not created");
	}
	return program;
}
}

