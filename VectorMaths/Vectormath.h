#pragma once

struct Vec2 {
	float x;
	float y;
};

struct Vec3 {
	float x;
	float y;
	float z;
};

extern "C" __declspec(dllexport) Vec3 VectorAdd(Vec3 a, Vec3 b);