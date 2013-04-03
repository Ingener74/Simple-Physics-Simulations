/*
 * FileLogger.cpp
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#include "FileLogger.h"

FileLogger::FileLogger( const std::string& fileName ): ILog(){
	_file.open(fileName.c_str(), std::ios::out);
	if(!_file.is_open()){
		setError("could not open file");
	}
}

FileLogger::~FileLogger() {
	_file.flush();
	_file.close();
}

void FileLogger::put( const std::string& message ){
	if(_file.is_open()){
		_file << message << std::endl;
	}else{
		setError("could not open file");
	}
}
