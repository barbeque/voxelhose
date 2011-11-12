#ifndef _vxgeometry_h_
#define _vxgeometry_h_

#include <cmath>

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

// shorthands:
typedef vxVector vxV;

// global operators
inline vxVector operator* (float scalar, const vxVector& vector) {
	return vxVector(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

#endif

