#include "tests.h"
#include "../vxgeometry.h"

void vectorTests() {
	vxVector x(10, 10, 10);
	assert(x.length() == sqrtf(300));
}

void rayPlaneCollisionTests() {
	vxVector planeA(-5, 0, 0);
	vxVector planeB(5, 0, 0);
	vxVector planeC(5, 5, 0);

	// hit going forward
	vxRay testRay(vxVector(0, 2.5, -5), vxVector(0, 0, 1));
	assert(testRay.intersect(planeA, planeB, planeC).hit);

	// see if it hits even if the direction is backward
	vxRay infiniteHitRay(vxVector(0, 2.5, -5), vxVector(0, 0, -1));
	assert(infiniteHitRay.intersect(planeA, planeB, planeC).hit);
}

void rayCubeCollisionTests() {
	// hit a cube
	vxVector cubeA(0, 0, 0);
	vxVector cubeB(64, 64, 64);
	vxRay testRay(vxVector(-64, -64, -64), vxVector(1, 1, 1));
	assert(testRay.intersect(cubeA, cubeB).hit);

	// miss a cube
	vxRay antiTestRay(vxVector(70, 70, 70), vxVector(-1, -1, 0));
	assert(!antiTestRay.intersect(cubeA, cubeB).hit);
}

int main() {
	vectorTests();
	rayPlaneCollisionTests();
	rayCubeCollisionTests();

	std::cout << "all tests passed" << std::endl;
	return 0;
}
