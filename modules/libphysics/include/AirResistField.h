/*
 * AirResistField.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef AIRRESISTFIELD_H_
#define AIRRESISTFIELD_H_

#include "IForceField.h"
#include "MaterialPoint.h"

namespace psp{

namespace physics {

class AirResistField: public IForceField<MaterialPoint, Vector<double> > {
public:
	AirResistField( double airResistance = 1.0 );
	virtual ~AirResistField();

	Vector<double> Force( const MaterialPoint& materialPoint );

private:
	double _airResistance;
};

} /* namespace physics */
}
#endif /* AIRRESISTFIELD_H_ */
