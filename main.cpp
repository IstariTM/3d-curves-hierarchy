#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <random>
#include <omp.h>

#include "3d_curves.h"

std::vector<Curve3D*> generateRandomCurves(int curvesCount) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> curveTypeDist(1, 3);
	std::uniform_real_distribution<> radiusDist(1.0, 10.0);
	std::uniform_real_distribution<> stepDist(1.0, 5.0);

	std::vector<Curve3D*> curves;

	for (int i = 0; i < curvesCount; ++i) {
		Curve3D* curve;

		int curveType = curveTypeDist(gen);
		if (curveType == 1) {
			curve = new Circle(radiusDist(gen));
		}
		else if (curveType == 2) {
			curve = new Ellipse(radiusDist(gen), radiusDist(gen));
		}
		else if (curveType == 3) {
			curve = new Helix(radiusDist(gen), stepDist(gen));
		}

		curves.push_back(curve);
	}

	return curves;
}

void printPointsAndDerivatives(std::vector<Curve3D*> curves, double t) {
	for (const auto& curve : curves) {
		std::cout << "Curve type: " << curve->type() << std::endl;
		Vector3D point = curve->getPoint(t);
		std::cout << "point : " << point << std::endl;
		Vector3D derivative = curve->getDerivative(t);
		std::cout << "derivative : " << derivative << std::endl;
	}
};

int main() {

	int curvesCount = 100;
	std::vector<Curve3D*> curves = generateRandomCurves(curvesCount);

	double t = M_PI_4;
	printPointsAndDerivatives(curves, t);

	std::vector<Curve3D*> circles;
	std::copy_if(curves.begin(), curves.end(), std::back_inserter(circles), 
		[](Curve3D* it) { return  (dynamic_cast<Circle*>(it) != nullptr); });
	
	std::sort(circles.begin(), circles.end(), [](auto i1, auto i2) { return i1->radius() < i2->radius(); });

	//totalSum = std::accumulate(circles.begin(), circles.end(), 0., [](auto a, auto b) { return (a + b->radius()); });
	double totalSum = 0.0;
	#pragma omp parallel for reduction(+:totalSum)
	{
 		for (int i = 0; i < circles.size(); ++i) {
 			totalSum += circles[i]->radius();
 		}
	}
	std::cout << "Total sum of radii: " << totalSum << std::endl;
	
	for (auto curve : curves) {
		delete curve;
	}

	return 0;
}

