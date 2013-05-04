/*
 * IShaderLoader.h
 *
 *  Created on: 31.03.2013
 *      Author: ingener
 */

#ifndef ISHADERLOADER_H_
#define ISHADERLOADER_H_

namespace gltools{

class IShaderLoader{
public:
	IShaderLoader();
	virtual ~IShaderLoader();

	virtual const char* getVertexSource()   = 0;
	virtual const char* getFragmentSource() = 0;
};
}


#endif /* ISHADERLOADER_H_ */
