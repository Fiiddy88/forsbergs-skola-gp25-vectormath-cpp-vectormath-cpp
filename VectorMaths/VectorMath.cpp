//ALWAYS include the pch.h FIRST IN EVERY CPP FILE WHERE YOU NEED IT
#include "pch.h"

//THEN INCLUDE OWN ITEMS
#include "Vectormath.h"

//Vec3

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

//DOT

extern "C" float VectorDot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

//CROSS

extern "C" Vec3 VectorCross(Vec3 a, Vec3 b) {
    return Vec3{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}
//SCALE

extern "C" Vec3 VectorScale(Vec3 v, float s) {
    return Vec3{ v.x * s, v.y * s, v.z * s };
}

//REFLECT

extern "C" Vec3 VectorReflect(Vec3 v, Vec3 normal) {
    float dot = VectorDot(v, normal) * 2.0f;
    return VectorSubtract(v, VectorScale(normal, dot));
}

//DISTANCE

extern "C" float VectorDistance(Vec3 a, Vec3 b) {
    Vec3 diff = VectorSubtract(a, b);
    return VectorMagnitude(diff);
}

//Squared Distance

extern "C" float VectorDistanceSqr(Vec3 a, Vec3 b) {
    Vec3 diff = VectorSubtract(a, b);
    return diff.x * diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
}

//LERP

extern "C" Vec3 VectorLerp(Vec3 a, Vec3 b, float t) {
    t = std::clamp(t, 0.0f, 1.0f);
    return VectorAdd(a, VectorScale(VectorSubtract(b, a), t));
}

//CLAMP

extern "C" Vec3 VectorClamp(Vec3 v, float min, float max) {
    return Vec3{
        std::clamp(v.x, min, max),
        std::clamp(v.y, min, max),
        std::clamp(v.z, min, max)
    };
}

//Vec2

//Addition
        extern "C" Vec2 Vector2Add(Vec2 a, Vec2 b) {
        return Vec2{ a.x + b.x, a.y + b.y };
    }

//Subtract

    extern "C" Vec2 Vector2Subtract(Vec2 a, Vec2 b) {
        return Vec2{ a.x - b.x, a.y - b.y };
    }

//Scale

    extern "C" Vec2 Vector2Scale(Vec2 v, float s) {
        return Vec2{ v.x * s, v.y * s };
    }

//Magnitude

    extern "C" float Vector2Magnitude(Vec2 v) {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

//Normalize

    extern "C" Vec2 Vector2Normalize(Vec2 v) {
        float mag = Vector2Magnitude(v);
        if (mag < 0.0001f) return Vec2{ 0.0f, 0.0f };
        return Vec2{ v.x / mag, v.y / mag };
    }

//Dot

    extern "C" float Vector2Dot(Vec2 a, Vec2 b) {
        return a.x * b.x + a.y * b.y;
    }

//Distance

    extern "C" float Vector2Distance(Vec2 a, Vec2 b) {
        Vec2 diff = Vector2Subtract(a, b);
        return Vector2Magnitude(diff);
    }

//Squared Distance

    extern "C" float Vector2DistanceSqr(Vec2 a, Vec2 b) {
        Vec2 diff = Vector2Subtract(a, b);
        return diff.x * diff.x + diff.y * diff.y;
    }