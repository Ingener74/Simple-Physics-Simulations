/*
 * FileLogger.h
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#ifndef FILELOGGER_H_
#define FILELOGGER_H_

#include <fstream>

#include "ILog.h"

class FileLogger: public ILog {
public:
	FileLogger( const std::string& fileName );
	virtual ~FileLogger();

	void put( const std::string& message );

private:
	std::ofstream _file;
};

#endif /* FILELOGGER_H_ */
