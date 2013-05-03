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

class GravityField: public IForceField<MaterialPoint, cv::Point3d> {
public:
	GravityField( double gravityAccleration );
	virtual ~GravityField();

	cv::Point3d Force( const MaterialPoint& materialPoint );

private:
	double _gravityAccleration;
};

} /* namespace physics */
#endif /* GRAVITYFIELD_H_ */
