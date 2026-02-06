//ALWAYS include the pch.h FIRST IN EVERY CPP FILE WHERE YOU NEED IT
#include "pch.h"

//THEN INCLUDE OWN ITEMS
#include "Vectormath.h"

extern "C" __declspec(dllexport) Vec3 VectorAdd(Vec3 a, Vec3 b) {
	return Vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
}