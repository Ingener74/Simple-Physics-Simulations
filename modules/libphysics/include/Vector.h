/*
 * Point.h
 *
 *  Created on: 18.07.2013
 *      Author: pavel
 */

#ifndef POINT_H_
#define POINT_H_

namespace psp {

namespace physics {

template<typename T>
class Vector {
public:
	Vector(T x = T(0), T y = T(0), T z = T(0)) :
			_x(x), _y(y), _z(z) {
	}
	virtual ~Vector() {
	}

	Vector operator+( const Vector& v ){
		return Vector(
				_x + v._x,
				_y + v._y,
				_z + v._z);
	}

	Vector operator*( const Vector& v ){
		return Vector(
				_x * v._x,
				_y * v._y,
				_z * v._z);
	}

	Vector operator*( double s ){
		return Vector(
				_x * s,
				_y * s,
				_z * s);
	}

	T _x, _y, _z;
private:
};

}
}

#endif /* POINT_H_ */
