/*
 * StringShaderLoader.h
 *
 *  Created on: 03.05.2013
 *      Author: pavel
 */

#ifndef STRINGSHADERLOADER_H_
#define STRINGSHADERLOADER_H_

#include "IShaderLoader.h"

namespace gltools {

class StringShaderLoader: public IShaderLoader {
public:
	StringShaderLoader( const char* vertexShaderSource, const char* fragmentShaderSource );
	virtual ~StringShaderLoader();

	const char* getVertexSource(){
		return _vertexShaderSource;
	}
	const char* getFragmentSource(){
		return _fragmentShaderSource;
	}
private:
	const char* _vertexShaderSource;
	const char* _fragmentShaderSource;
};

} /* namespace gltools */
#endif /* STRINGSHADERLOADER_H_ */
