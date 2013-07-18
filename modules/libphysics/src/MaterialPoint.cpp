/*
 * MaterialPoint.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include <stdint.h>

#include "MaterialPoint.h"

namespace psp{

namespace physics {

MaterialPoint::MaterialPoint(const Vector<double>& position,
		const Vector<double>& velocity, const Vector<double>& acceleration,
		double mass) :
		_pos(position), _vel(velocity), _acc(acceleration), _mass(mass) {
}

MaterialPoint::~MaterialPoint() {
}

void MaterialPoint::update(const std::vector<Vector<double>*>& forces,
		const std::vector<IForceField<MaterialPoint, Vector<double> >*>& forceFields, double deltaTime) {
	Vector<double> forceSum(0, 0, 0);
	for (uint32_t i = 0; i < forces.size(); ++i)
		forceSum = forceSum + *forces[i];
	for (uint32_t i = 0; i < forceFields.size(); ++i) {
		forceSum = forceSum + forceFields[i]->Force(*this);
	}

	_acc = forceSum * (1.0 / _mass);

	_vel = _vel + _acc * deltaTime;
	_pos = _pos + _vel * deltaTime;
}

} /* namespace physics */
}

