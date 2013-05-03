/*
 * GravityField.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include "GravityField.h"

namespace physics {

GravityField::GravityField( double gravityAcceleration ):
		_gravityAccleration(gravityAcceleration){
}

GravityField::~GravityField() {
}

cv::Point3d GravityField::Force( const MaterialPoint& materialPoint ){
	return cv::Point3d(0.0, -_gravityAccleration * materialPoint.getMass(), 0.0);
}

} /* namespace physics */
