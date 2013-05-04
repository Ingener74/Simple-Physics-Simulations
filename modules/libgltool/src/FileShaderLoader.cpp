/*
 * FileShaderLoader.cpp
 *
 *  Created on: 31.03.2013
 *      Author: ingener
 */

#include "FileShaderLoader.h"

namespace gltools{

FileShaderLoader::FileShaderLoader( const char* vertexFile,
		const char* fragmentFile) {

	for( uint32_t i = 0; i < maxFileSize; ++i ){
		vertexSource[i] = 0;
		fragmentSource[i] = 0;
	}

	ifstream vsFile(vertexFile);
	if(vsFile.is_open()){

		uint32_t s = vsFile.tellg();
		vsFile.seekg(0, ios::end);
		uint32_t e = vsFile.tellg();
		vsFile.seekg(0, ios::beg);

		vsFile.read(vertexSource, (e - s));

		ErrorLogger::getInstance()->put(ErrorLogger::ERROR, "vertex source = %d", (e - s));
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "vs = %s", vertexSource);

		vsFile.close();

	}else{
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "error: could not open vertex source file");
	}

	ifstream fsFile(fragmentFile);
	if(fsFile.is_open()){

		uint32_t s = fsFile.tellg();
		fsFile.seekg(0, ios::end);
		uint32_t e = fsFile.tellg();
		fsFile.seekg(0, ios::beg);

		fsFile.read(fragmentSource, (e - s));

		ErrorLogger::getInstance()->put(ErrorLogger::ERROR, "fragment source = %d", (e - s));
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "fs = %s", fragmentSource);

		fsFile.close();

	}else{
		ErrorLogger::getInstance()->put(ErrorLogger::FATAL_ERROR, "error: could not open fragment source file");
	}
}

FileShaderLoader::~FileShaderLoader() {
}

const char* FileShaderLoader::getVertexSource(){
	return vertexSource;
}
const char* FileShaderLoader::getFragmentSource(){
	return fragmentSource;
}
}




