/*
 * MaterialPoint.cpp
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#include "MaterialPoint.h"

namespace physics {

MaterialPoint::MaterialPoint(const cv::Point3d& position,
		const cv::Point3d& velocity, const cv::Point3d& acceleration,
		double mass) :
		_pos(position), _vel(velocity), _acc(acceleration), _mass(mass) {
}

MaterialPoint::~MaterialPoint() {
}

void MaterialPoint::update(const std::vector<cv::Point3d*>& forces,
		const std::vector<IForceField<MaterialPoint>*>& forceFields, double deltaTime) {
	cv::Point3d forceSum(0, 0, 0);
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
