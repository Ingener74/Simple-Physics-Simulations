/*
 * MaterialPoint.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef MATERIALPOINT_H_
#define MATERIALPOINT_H_

#include <vector>

#include "Vector.h"

#include "IForceField.h"

namespace psp{

namespace physics {

class MaterialPoint {
public:
	MaterialPoint(
			const Vector<double>& position = Vector<double>(),
			const Vector<double>& velocity = Vector<double>(),
			const Vector<double>& acceleration = Vector<double>(),
			double mass = 1.0);
	virtual ~MaterialPoint();

	const Vector<double>& getPosition() const {
		return _pos;
	}
	const Vector<double>& getVelocity() const {
		return _vel;
	}
	const Vector<double>& getAccleration() const {
		return _acc;
	}
	double getMass() const {
		return _mass;
	}

	virtual void update(const std::vector<Vector<double>* >& forces,
			const std::vector< IForceField<MaterialPoint, Vector<double> >* >& forceFields, double deltaTime);

private:
	Vector<double> _pos;
	Vector<double> _vel;
	Vector<double> _acc;

	double _mass;
};

} /* namespace physics */
}

#endif /* MATERIALPOINT_H_ */
