/*
 * IForceField.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef IFORCEFIELD_H_
#define IFORCEFIELD_H_

namespace physics {

template<typename tMaterialPointType, typename tVectorType>
class IForceField {
public:
	IForceField() {
	}
	virtual ~IForceField() {
	}

	virtual tVectorType Force(const tMaterialPointType& materialPoint) = 0;
};

} /* namespace physics */
#endif /* IFORCEFIELD_H_ */
