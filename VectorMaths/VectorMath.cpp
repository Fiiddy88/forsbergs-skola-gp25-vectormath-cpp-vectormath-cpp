//ALWAYS include the pch.h FIRST IN EVERY CPP FILE WHERE YOU NEED IT
#include "pch.h"

//THEN INCLUDE OWN ITEMS
#include "Vectormath.h"
//ADDITION
extern "C" Vec3 VectorAdd(Vec3 a, Vec3 b) {
    return Vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
}
//SUBRATRACTION
extern "C" Vec3 VectorSubtract(Vec3 a, Vec3 b) {
    return Vec3{ a.x - b.x, a.y - b.y, a.z - b.z };
}
//MAGNITUDE
extern "C" float VectorMagnitude(Vec3 v) {  
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
//NORMALIZE
extern "C" Vec3 VectorNormalize(Vec3 v) {
    float mag = VectorMagnitude(v);  
    if (mag == 0.0f) {
        return Vec3{ 0.0f, 0.0f, 0.0f };
    }
    return Vec3{  
        v.x / mag,
        v.y / mag,
        v.z / mag
    };
}
