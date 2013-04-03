/*
 * ErrorHandler.h
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#ifndef ERRORHANDLER_H_
#define ERRORHANDLER_H_

#include <string>

class ErrorHandler {
public:
	ErrorHandler();
	virtual ~ErrorHandler();

	void setError( const std::string& errorString = _defaultErrorString, bool isError = true );

private:
	bool         _isError;
	std::string  _errorString;

	static const char* _success;
	static const char* _defaultErrorString;
};

#endif /* ERRORHANDLER_H_ */
