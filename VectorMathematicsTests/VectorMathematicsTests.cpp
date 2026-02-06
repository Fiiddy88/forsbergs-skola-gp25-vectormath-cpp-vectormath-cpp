#include <iostream>
#include <cmath>

struct Vec3 {
    float x, y, z;
};

Vec3 VectorAdd(Vec3 a, Vec3 b) {
    return { a.x + b.x, a.y + b.y, a.z + b.z };
}

int main()
{
    auto added = VectorAdd({ 1,2,3 }, { 1,2,3 });
    std::cout << added.x << ", " << added.y << ", " << added.z << std::endl;
    std::cin.get();
}
