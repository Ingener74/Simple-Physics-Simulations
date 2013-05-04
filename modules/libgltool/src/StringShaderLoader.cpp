/*
 * StringShaderLoader.cpp
 *
 *  Created on: 03.05.2013
 *      Author: pavel
 */

#include "StringShaderLoader.h"

namespace gltools {

StringShaderLoader::StringShaderLoader(const char* vertexShaderSource,
		const char* fragmentShaderSource) :
		_vertexShaderSource(vertexShaderSource), _fragmentShaderSource(
				fragmentShaderSource) {
}

StringShaderLoader::~StringShaderLoader() {
}

} /* namespace gltools */
