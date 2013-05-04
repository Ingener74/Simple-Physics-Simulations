/*
 * ErrorLogger.h
 *
 *  Created on: 03.05.2013
 *      Author: pavel
 */

#ifndef ERRORLOGGER_H_
#define ERRORLOGGER_H_

#include <string>

namespace gltools {

class ErrorLogger {
public:
	typedef enum {
		INFO,
		ERROR,
		FATAL_ERROR
	} ERROR_STATUS ;

	static ErrorLogger* getInstance();
	static void put( ERROR_STATUS errorStatus, const char* format, ... );

	virtual ~ErrorLogger();

private:
	ErrorLogger();
	static ErrorLogger* _instance;
};

} /* namespace gltools */
#endif /* ERRORLOGGER_H_ */
