/*
 * Point.h
 *
 *  Created on: 18.07.2013
 *      Author: pavel
 */

#ifndef POINT_H_
#define POINT_H_

template <typename T>
class Point {
public:
	Point( T x = T(0), T y = T(0), T z = T(0)): _x(x), _y(y), _z(z){
	}
	virtual ~Point();

	const T& getX() const { return _x; }
	const T& getY() const { return _y; }
	const T& getZ() const { return _z; }

private:
	T _x, _y, _z;
};

#endif /* POINT_H_ */
