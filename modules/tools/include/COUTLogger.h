/*
 * COUTLogger.h
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#ifndef COUTLOGGER_H_
#define COUTLOGGER_H_

#include "ILog.h"

class COUTLogger: public ILog {
public:
	COUTLogger();
	virtual ~COUTLogger();

	void put( const std::string& message );
};

#endif /* COUTLOGGER_H_ */
