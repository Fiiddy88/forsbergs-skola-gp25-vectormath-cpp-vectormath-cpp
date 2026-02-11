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

	VECTORMATH_API float VectorDot(Vec3 a, Vec3 b);
	VECTORMATH_API Vec3 VectorCross(Vec3 a, Vec3 b);
	VECTORMATH_API Vec3 VectorScale(Vec3 v, float s);
	VECTORMATH_API Vec3 VectorReflect(Vec3 v, Vec3 normal);
	VECTORMATH_API float VectorDistance(Vec3 a, Vec3 b);
	VECTORMATH_API Vec3 VectorLerp(Vec3 a, Vec3 b, float t);
	VECTORMATH_API Vec3 VectorClamp(Vec3 v, float min, float max);

	VECTORMATH_API Vec2 Vector2Add(Vec2 a, Vec2 b);
	VECTORMATH_API Vec2 Vector2Subtract(Vec2 a, Vec2 b);
	VECTORMATH_API Vec2 Vector2Scale(Vec2 v, float s);
	VECTORMATH_API float Vector2Magnitude(Vec2 v);
	VECTORMATH_API Vec2 Vector2Normalize(Vec2 v);
	VECTORMATH_API float Vector2Dot(Vec2 a, Vec2 b);

}