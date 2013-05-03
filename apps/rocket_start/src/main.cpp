#include <iostream>
#include <vector>

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

	physics::MaterialPoint rocket(cv::Point3d(100, 0, 0), cv::Point3d(),
			cv::Point3d(), 10.0);
	cv::Point3d rocketForce(0.0, 500.0, 0.0);

	physics::GravityField gravity(9.8);
	physics::AirResistField airResist(1.0);

	std::vector<cv::Point3d*> forces;
	forces.push_back(&rocketForce);

	std::vector<physics::IForceField<physics::MaterialPoint, cv::Point3d>*> forceFields;
	forceFields.push_back(&gravity);
	forceFields.push_back(&airResist);

	while (1) {

		im = cv::Mat(1000, 200, CV_8UC3, cv::Scalar(0, 150, 70));

		rocket.update(forces, forceFields, dt);

		cv::circle(im,
				cv::Point(rocket.getPosition().x,
						im.rows - rocket.getPosition().y), 3,
				cv::Scalar(255, 0, 0), -1);
		imshow("im", im);

		std::cout << "P = " << rocket.getPosition() << ",\tV = "
				<< rocket.getVelocity() << ",\tA = " << rocket.getAccleration()
				<< std::endl;

		char c = cv::waitKey(fps_dt);
		if (c == 27) {
			return 0;
		}
	}

	return 0;
}
