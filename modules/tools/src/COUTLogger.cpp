/*
 * COUTLogger.cpp
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */
#include <iostream>

#include "COUTLogger.h"

COUTLogger::COUTLogger() {
}

COUTLogger::~COUTLogger() {
}

void COUTLogger::put( const std::string& message ){
	std::cout << message << std::endl;
}
