/*
 * main.cpp
 *
 *  Created on: 03.05.2013
 *      Author: pavel
 */

#include <iostream>
#include <vector>

#include <ShaderProgram.h>
#include <StringShaderLoader.h>

#include <GL/glut.h>

gltools::ShaderProgram* sp;

const char* caption =
		"Material Point on 4 spring"
		;

const char* vertex_source =
		"attribute vec2 coord2d;"
		""
		"void main(void){ "
		"	gl_Position = vec4(coord2d, 0.0, 1.0); "
		"}"
		;

const char* fragment_shader =
		"void main(void){"
		"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); "
		"}"
		;

void display(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.4f, 0.2f, 1.f);

	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
}

int main( int argc, char* argv[] ){

	std::cout << caption << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutCreateWindow("Material point on four spring");

	GLenum err = glewInit();
	if(err != GLEW_OK){
		gltools::ErrorLogger::getInstance()->put(gltools::ErrorLogger::FATAL_ERROR, "glew error");
	}

	gltools::StringShaderLoader ssl(vertex_source, fragment_shader);
	sp = new gltools::ShaderProgram(&ssl);

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();

	delete sp;

	return 0;
}


