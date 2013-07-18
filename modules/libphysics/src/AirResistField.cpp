/*
 * AirResistField.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include <cmath>

#include "AirResistField.h"

namespace psp{

namespace physics {

AirResistField::AirResistField( double airResistance ):
		_airResistance(airResistance){
}

AirResistField::~AirResistField() {
}

Vector<double> AirResistField::Force( const MaterialPoint& materialPoint ){
	const Vector<double>& v = materialPoint.getVelocity();
	double vm = sqrt(v._x*v._x + v._y*v._y + v._z*v._z);
	return Vector<double>(
			-vm*v._x*v._x,
			-vm*v._y*v._y,
			-vm*v._z*v._z );
}

} /* namespace physics */
}
