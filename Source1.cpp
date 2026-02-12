#include "VectorMath.h"
#include <cmath>

// Vector 3

Vec3 VectorAdd(Vec3 a, Vec3 b) {
	return { a.x + b.x, a.y + b.y, a.z + b.z }
}

Vec3 VectorSubract(Vec3 a, Vec3 b) {
	return { a.x - b.x, a.y - b.y, a.z - b.z }
}

// Vector 2



Vec3 VectorAdd(Vec2 a, Vec2 b) {
	return { a.x + b.x, a.y + b.y}
}

Vec3 VectorSubract(Vec3 a, Vec3 b) {
	return { a.x - b.x, a.y - b.y}
}

//Other

float VectorMagnitude(Vec3 v) {
	return sqrt (v.x *v.x + v.y*v.y + v.z*v.z)
}

Vec3 VectorNormalize(Vec3 v) {
	float mag = VectorMagnitude(v);
	if (mag < 0.00001f) return (0, 0, 0);
	return (v.x / mag, v.y / mag, v.z / mag);

}

//Why split them

/*
RULE OF THUMB
IF SOMEONE NEED STO KNOW IT EXITST PUT IT IN A HEADER FILE
IF SOMEONE NEEDS TO KNOW HOW IT WORKS PUT IT IN THE.cpp FILE

KEEPS CODE MODULAR AND EFFICIENT 

*/
