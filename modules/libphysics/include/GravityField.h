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

namespace psp{

namespace physics {

class GravityField: public IForceField<MaterialPoint, Vector<double> > {
public:
	GravityField( double gravityAccleration );
	virtual ~GravityField();

	Vector<double> Force( const MaterialPoint& materialPoint );

private:
	double _gravityAccleration;
};

} /* namespace physics */
}

#endif /* GRAVITYFIELD_H_ */
