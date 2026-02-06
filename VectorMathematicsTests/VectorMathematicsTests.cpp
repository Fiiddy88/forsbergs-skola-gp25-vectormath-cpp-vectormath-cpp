#include <iostream>
#include <cmath>
#include "Vectormath.h"

int main()
{
	Vec3 a{ 3.0f, 4.0f, 0.0f };
	Vec3 b{ 1.0f, 2.0f, 3.0f };

	Vec3 added = VectorAdd(a, b);
	Vec3 sub = VectorSubtract(a, b);
	float mag = VectorMagnitude(a);
	Vec3 norm = VectorNormalize(a);

	std::cout << "Add; "
		<< added.x << ", "
		<< added.y << ", "
		<< added.z << std::endl;

	std::cout << "Sub; "
		<< sub.x << ", "
		<< sub.y << ", "
		<< sub.z << std::endl;

	std::cout << "Magnitude: " << mag << std::endl;
	std::cout << "Normalize: "
		<< norm.x << ", "
		<< norm.y << ", "
		<< norm.z << std::endl;

	std::cin.get();
	return 0;
}