/*
 * ErrorLogger.cpp
 *
 *  Created on: 03.05.2013
 *      Author: pavel
 */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include <iostream>

#include "ErrorLogger.h"

namespace gltools {

ErrorLogger* ErrorLogger::_instance = NULL;

ErrorLogger* ErrorLogger::getInstance(){
	if(!_instance){
		_instance = new ErrorLogger();
	}
	return _instance;
}

void ErrorLogger::put( ERROR_STATUS errorStatus, const char* format, ... ){
	va_list arglist;
	va_start(arglist, format);
	vprintf(format, arglist);
	va_end(arglist);
	if(errorStatus == FATAL_ERROR){
		exit(EXIT_FAILURE);
	}
}

ErrorLogger::ErrorLogger() {
}
ErrorLogger::~ErrorLogger() {
}

} /* namespace gltools */
