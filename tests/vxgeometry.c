#include "tests.h"
#include "../vxgeometry.h"

void vectorTests() {
	vxVector x(10, 10, 10);
	assert(x.length() == sqrtf(300));
}

int main() {
	vectorTests();

	std::cout << "all tests passed" << std::endl;
	return 0;
}
