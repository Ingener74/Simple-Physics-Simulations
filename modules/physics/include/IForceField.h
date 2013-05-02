/*
 * IForceField.h
 *
 *  Created on: 02.05.2013
 *      Author: pavel
 */

#ifndef IFORCEFIELD_H_
#define IFORCEFIELD_H_

#include <opencv2/core/core.hpp>

namespace physics {

template<typename tMaterialPointType>
class IForceField {
public:
	IForceField(){}
	virtual ~IForceField(){}

	virtual cv::Point3d Force( const tMaterialPointType& materialPoint ) = 0;
};

} /* namespace physics */
#endif /* IFORCEFIELD_H_ */
