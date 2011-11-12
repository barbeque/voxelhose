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

	vxRay testRay(vxVector(0, 2.5, -5), vxVector(0, 0, 1));

	assert(testRay.intersect(planeA, planeB, planeC).hit);
}

int main() {
	vectorTests();
	rayPlaneCollisionTests();

	std::cout << "all tests passed" << std::endl;
	return 0;
}
