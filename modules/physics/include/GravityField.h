/*
 * GravityField.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef GRAVITYFIELD_H_
#define GRAVITYFIELD_H_

#include "IForceField.h"
#include "MaterialPoint.h"

namespace physics {

class GravityField: public IForceField<MaterialPoint> {
public:
	GravityField(double gravityAccleration);
	virtual ~GravityField();

	cv::Point3d Force( const MaterialPoint& materialPoint ){
		return cv::Point3d(0.0, -_gravityAccleration * materialPoint.getMass(), 0.0);
	}
private:
	double _gravityAccleration;
};

} /* namespace physics */
#endif /* GRAVITYFIELD_H_ */
