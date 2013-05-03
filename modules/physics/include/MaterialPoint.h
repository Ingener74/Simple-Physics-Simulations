/*
 * MaterialPoint.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef MATERIALPOINT_H_
#define MATERIALPOINT_H_

#include <vector>

#include <opencv2/core/core.hpp>

#include "IForceField.h"

namespace physics {

class MaterialPoint {
public:
	MaterialPoint(const cv::Point3d& position = cv::Point3d(),
			const cv::Point3d& velocity = cv::Point3d(),
			const cv::Point3d& acceleration = cv::Point3d(),
			double mass = 1.0);
	virtual ~MaterialPoint();

	const cv::Point3d& getPosition() const {
		return _pos;
	}
	const cv::Point3d& getVelocity() const {
		return _vel;
	}
	const cv::Point3d& getAccleration() const {
		return _acc;
	}
	double getMass() const {
		return _mass;
	}

	virtual void update(const std::vector<cv::Point3d*>& forces,
			const std::vector<IForceField<MaterialPoint, cv::Point3d>*>& forceFields, double deltaTime);

private:
	cv::Point3d _pos;
	cv::Point3d _vel;
	cv::Point3d _acc;

	double _mass;
};

} /* namespace physics */
#endif /* MATERIALPOINT_H_ */
