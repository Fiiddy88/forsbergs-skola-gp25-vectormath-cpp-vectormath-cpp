#include "pch.h"  // Add this FIRST!
#include "Vectormath.h"
#include <iostream>
#include <iomanip>

int main() {
    Vec3 a{ 3.0f, 4.0f, 0.0f };
    Vec3 b{ 1.0f, 2.0f, 3.0f };

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Add: (" << VectorAdd(a, b).x << ", "
        << VectorAdd(a, b).y << ", " << VectorAdd(a, b).z << ")\n";
    std::cout << "Sub: (" << VectorSubtract(a, b).x << ", "
        << VectorSubtract(a, b).y << ", " << VectorSubtract(a, b).z << ")\n";
    std::cout << "Mag: " << VectorMagnitude(a) << "\n";
    std::cout << "Norm: (" << VectorNormalize(a).x << ", "
        << VectorNormalize(a).y << ", " << VectorNormalize(a).z << ")\n";

    Vec2 a2{ 3.0f,4.0f };
    Vec2 b2{ 1.0f,2.0f };

    std::cout << "Vec2 Add: (" << Vector2Add(a2, b2).x << ", "
        << Vector2Add(a2, b2).y << ")\n";
    std::cout << "Vec2 Sub: (" << Vector2Subtract(a2, b2).x << ", "
        << Vector2Subtract(a2, b2).y << ")\n";
    std::cout << "Vec2 Mag: " << Vector2Magnitude(a2) << "\n";
    std::cout << "Vec2 Norm: (" << Vector2Normalize(a2).x << ", "
        << Vector2Normalize(a2).y << ")\n";
    std::cout << "Vec2 Dot: " << Vector2Dot(a2, b2) << "\n";

    std::cin.get();
    return 0;
}
