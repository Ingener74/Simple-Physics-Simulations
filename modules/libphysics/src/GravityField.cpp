/*
 * GravityField.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include "GravityField.h"

namespace psp{

namespace physics {

GravityField::GravityField( double gravityAcceleration ):
		_gravityAccleration(gravityAcceleration){
}

GravityField::~GravityField() {
}

Vector<double> GravityField::Force( const MaterialPoint& materialPoint ){
	return Vector<double>(0.0, -_gravityAccleration * materialPoint.getMass(), 0.0);
}

} /* namespace physics */
}
