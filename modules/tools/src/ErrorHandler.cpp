/*
 * ErrorHandler.cpp
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#include "ErrorHandler.h"

ErrorHandler::ErrorHandler(): _isError(false), _errorString(_defaultErrorString) {
}

ErrorHandler::~ErrorHandler() {
}

void ErrorHandler::setError( const std::string& errorString, bool isError ){
	_errorString = errorString;
	_isError     = isError;
}

const char* ErrorHandler::_success =
		"success"
		;
const char* ErrorHandler::_defaultErrorString =
		"default error string"
		;
