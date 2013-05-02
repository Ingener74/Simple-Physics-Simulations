/*
 * AirResistField.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include "AirResistField.h"

namespace physics {

AirResistField::AirResistField( double airResistance ):
		_airResistance(airResistance){
}

AirResistField::~AirResistField() {
}

cv::Point3d AirResistField::Force( const MaterialPoint& materialPoint ){
	const cv::Point3d& v = materialPoint.getVelocity();
	double vm = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	return cv::Point3d(
			-vm*v.x*v.x,
			-vm*v.y*v.y,
			-vm*v.z*v.z );
}

} /* namespace physics */
