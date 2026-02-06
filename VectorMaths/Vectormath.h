#pragma once

#ifdef VECTORMATH_EXPORTS
#define VECTORMATH_API __declspec(dllexport)
#else
#define VECTORMATH_API __declspec(dllimport)
#endif



struct Vec2 {
	float x;
	float y;
};

struct Vec3 {
	float x;
	float y;
	float z;
};

extern "C" {
	VECTORMATH_API Vec3 VectorAdd(Vec3 a, Vec3 b);
	VECTORMATH_API Vec3 VectorSubtract(Vec3 a, Vec3 b);

	VECTORMATH_API float VectorMagnitude(Vec3 v);
	VECTORMATH_API Vec3 VectorNormalize(Vec3 v);
}