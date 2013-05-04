/*
 * FileShaderLoader.h
 *
 *  Created on: 31.03.2013
 *      Author: ingener
 */

#ifndef FILESHADERLOADER_H_
#define FILESHADERLOADER_H_

#include <stdint.h>
#include <fstream>

#include "IShaderLoader.h"
#include "ErrorLogger.h"

namespace gltools{

using namespace std;

class FileShaderLoader: public IShaderLoader {
public:
	FileShaderLoader(
			const char* vertexShaderFile,
			const char* fragmentShaderFile );
	virtual ~FileShaderLoader();

	const char* getVertexSource();
	const char* getFragmentSource();

private:
	const static uint32_t maxFileSize = 1024 * 10;
	char vertexSource[maxFileSize];
	char fragmentSource[maxFileSize];
};
}


#endif /* FILESHADERLOADER_H_ */
