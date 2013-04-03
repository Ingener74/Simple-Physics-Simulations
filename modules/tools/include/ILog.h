/*
 * ILog.h
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */
#ifndef ILOG_H_
#define ILOG_H_

#include <string>

#include "ErrorHandler.h"

class ILog: public ErrorHandler{
public:
	virtual ~ILog(){}
	virtual void put( const std::string& message ) = 0;
};

#endif /* ILOG_H_ */
