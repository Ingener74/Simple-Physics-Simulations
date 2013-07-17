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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// window
uint16_t windowWidth = 1024, windowHeight = 768;


gltools::ShaderProgram* sp;
GLuint aPOS = 0;
GLuint uMVP = 0;

glm::mat4 projMat;
glm::mat4 viewMat;
float FOVy = 45.f, nearPlane = 0.1f, farPlane = 1000.f;

GLfloat coords[] = {
		 0.f,  0.f, 0.5f,
		-1.f, -1.f,  0.f,

		 0.f,  0.f, 0.5f,
		-1.f,  1.f,  0.f,

		 0.f,  0.f, 0.5f,
		 1.f, -1.f,  0.f,

		 0.f,  0.f, 0.5f,
		 1.f,  1.f,  0.f
};
GLuint coordBuffer = 0;

const char* caption =
		"Material Point on 4 spring"
		;

const char* vertex_source =
		"attribute vec4 aPOS;"
		"uniform   mat4 uMVP;"
		"void main(void){ "
		"	gl_Position = uMVP * aPOS;"
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

	sp->useProgram();

	glBindBuffer(GL_ARRAY_BUFFER, coordBuffer);

	glm::mat4 mvp = projMat * viewMat * glm::mat4();

	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(mvp));

	glVertexAttribPointer(aPOS, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(aPOS);

	glDrawArrays(GL_LINES, 0, 8);

	glDisableVertexAttribArray(aPOS);

	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	projMat = glm::perspective(FOVy, w / float(h), nearPlane, farPlane);
}

void init(){
	gltools::StringShaderLoader ssl(vertex_source, fragment_shader);
	sp = new gltools::ShaderProgram(&ssl);
	aPOS = sp->getAttribute("aPOS");
	uMVP = sp->getUniform("uMVP");

	glGenBuffers(1, &coordBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, coordBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);

	projMat = glm::perspective(FOVy, windowHeight / float(windowWidth), nearPlane, farPlane);
	viewMat = glm::lookAt(
			glm::vec3(2.f, 3.f, 4.f),
			glm::vec3(0.f, 0.f, 0.f),
			glm::vec3(0.f, 0.f, 1.f)
	);
}

int main( int argc, char* argv[] ){

	std::cout << caption << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Material point on four spring");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	GLenum err = glewInit();
	if(err != GLEW_OK){
		gltools::ErrorLogger::getInstance()->put(gltools::ErrorLogger::FATAL_ERROR, "glew error");
	}

	void init();

	glutMainLoop();

	delete sp;

	return 0;
}


