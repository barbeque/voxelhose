#ifndef _vxgeometry_h_
#define _vxgeometry_h_

#include <cmath>
#include <climits>
#include <cfloat>

class vxVector {
	public:
		vxVector(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
	public:
		float length() const {
			return sqrtf((x*x) + (y*y) + (z*z));
		}
		void normalize() {
			float l = length();
			x /= l;
			y /= l;
			z /= l;
		}
		vxVector getNormalized() const {
			vxVector normalized = vxVector(x, y, z);
			normalized.normalize();
			return normalized;
		}
	public:
		float dot(const vxVector& b) const {
			return (x * b.x + y * b.y + z * b.z);
		}
	public:
		inline vxVector operator+ (const vxVector& b) const {
			return vxVector(x + b.x, y + b.y, z + b.z);
		}
		inline vxVector operator- (const vxVector& b) const {
			return vxVector(x - b.x, y - b.y, z - b.z);
		}
		inline vxVector operator* (const float& b) const {
			return vxVector(x * b, y * b, z * b);
		}
		inline vxVector operator- () const {
			// negation
			return vxVector(-x, -y, -z);
		}
	public:
		static inline vxVector cross(const vxVector& a, const vxVector& b) {
			float x = (a.y * b.z) - (a.z * b.y);
			float y = (a.z * b.x) - (a.x * b.z);
			float z = (a.x * b.y) - (a.y * b.x);
			return vxVector(x, y, z);
		}
	public:
		float x;
		float y;
		float z;
};

class vxIntersection {
public:
	vxIntersection(bool hit) : near(0,0,0), far(0,0,0) { this->hit = hit; }
public:
	bool hit;
	vxVector near;
	vxVector far;
};

class vxRay {
public:
	vxVector origin;
	vxVector direction;

	// cube intersection
	vxIntersection intersect(const vxVector& cubeMin, const vxVector& cubeMax) const {
		vxVector near(FLT_MIN, FLT_MIN, FLT_MIN);
		vxVector far(FLT_MAX, FLT_MAX, FLT_MAX);

		// test X planes
		// test Y planes
		// test Z planes
	
		// survived all the tests, must have passed
		vxIntersection result = vxIntersection(true);
		result.near = near;
		result.far = far;
		return result;
	}

	// plane intersection
	vxIntersection intersect(const vxVector& a, const vxVector& b, const vxVector& c) {
		vxVector v1 = b - a;
		vxVector v2 = c - a;
		vxVector v3 = vxVector::cross(a, b);

		vxVector rotatedRay1 = vxVector(v1.dot(origin - a), v2.dot(origin - a), v3.dot(origin - a));
		vxVector rotatedRay2 = vxVector(v1.dot(direction - a), v2.dot(direction - a), v3.dot(direction - a));

		if(rotatedRay1.z == rotatedRay2.z) { return vxIntersection(false); } // parallel to plane


		// hit, find out where
		float f = rotatedRay1.z / (rotatedRay2.z - rotatedRay1.z);

		vxIntersection result(true);
		result.near = result.far = (origin + (origin - direction) * f);

		return result;
	}
};

// shorthands:
typedef vxVector vxV;

// global operators
inline vxVector operator* (float scalar, const vxVector& vector) {
	return vxVector(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

#endif

