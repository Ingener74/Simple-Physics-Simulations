#include <iostream>
#include <vector>

#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <MaterialPoint.h>
#include <GravityField.h>
#include <AirResistField.h>

const char caption[] = "Rocket start test";

int main() {

	std::cout << caption << std::endl;

	cv::Mat im;

	uint32_t fps = 60;
	uint32_t fps_dt = 1000 / fps;

	double dt = 1.0 / double(fps);

	psp::physics::MaterialPoint rocket(psp::physics::Vector<double>(100, 0, 0), psp::physics::Vector<double>(),
			psp::physics::Vector<double>(), 10.0);
	psp::physics::Vector<double> rocketForce(0.0, 500.0, 0.0);

	psp::physics::GravityField gravity(9.8);
	psp::physics::AirResistField airResist(1.0);

	std::vector<psp::physics::Vector<double>*> forces;
	forces.push_back(&rocketForce);

	std::vector<psp::physics::IForceField<psp::physics::MaterialPoint, psp::physics::Vector<double> >*> forceFields;
	forceFields.push_back(&gravity);
	forceFields.push_back(&airResist);

	while (1) {

		im = cv::Mat(1000, 200, CV_8UC3, cv::Scalar(0, 150, 70));

		rocket.update(forces, forceFields, dt);

		cv::circle(im,
				cv::Point(rocket.getPosition()._x,
						im.rows - rocket.getPosition()._y), 3,
				cv::Scalar(255, 0, 0), -1);
		imshow("im", im);

		printf("P: %f %f %f, V: %f %f %f, A: %f %f %f\n",
				rocket.getPosition()._x, rocket.getPosition()._y, rocket.getPosition()._z,
				rocket.getVelocity()._x, rocket.getVelocity()._y, rocket.getVelocity()._z,
				rocket.getAccleration()._x, rocket.getAccleration()._y, rocket.getAccleration()._z
				);

		char c = cv::waitKey(fps_dt);
		if (c == 27) {
			return 0;
		}
	}

	return 0;
}
