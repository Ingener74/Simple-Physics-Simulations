/*
 * IApplication.h
 *
 *  Created on: 03.04.2013
 *      Author: pavel
 */

#ifndef IAPPLICATION_H_
#define IAPPLICATION_H_

class IApplication{
public:
	virtual ~IApplication(){}

	typedef enum{
		STATUS_SUCCESS,
		STATUS_FAIL,
	} STATUS;

	virtual STATUS initialization()   = 0;
	virtual void   run()              = 0;
	virtual void   deinitialization() = 0;
};

#endif /* IAPPLICATION_H_ */
