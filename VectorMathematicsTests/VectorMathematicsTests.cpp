#include "pch.h"  // Add this FIRST!
#include "Vectormath.h"
#include <iostream>
#include <iomanip>

bool TestPassed = true;

void AssertFloat(float expected, float actual, const std::string& testName) {
    float tolerance = 0.01f;
    if (std::abs(expected - actual) > tolerance) {
        std::cout << "FAIL: " << testName << " (Expected;" << expected
            << ", Got: " << actual << ")\n";
        TestPassed = false;
    }else{
        std::cout << "PASS: " << testName << "\n";
    }
}

void AssertVec2(Vec2 expected, Vec2 actual, const std::string& testName) {
    AssertFloat(expected.x, actual.x, testName + ".x");
    AssertFloat(expected.y, actual.y, testName + ".y");
}

void AssertVec3(Vec3 expected, Vec3 actual, const std::string& testName) {
    AssertFloat(expected.x, actual.x, testName + ".x");
    AssertFloat(expected.y, actual.y, testName + ".y");
    AssertFloat(expected.z, actual.z, testName + ".z");
}

int main() {

    std::cout << "=== VectorMath Test === \n\n";

    std::cout << "=== Vec2 ===\n"; {
        
        Vec2 a{ 3.0f,4.0f };
        Vec2 b{ 1.0f,2.0f };

       //Addition
        AssertVec2(Vec2{ 4.0f,6.0f }, Vector2Add(a, b), "Vec2.Add");

        //Subtract
        AssertVec2(Vec2{ 2.0f, 2.0f }, Vector2Subtract(a, b), "Vec2.Subtract");

        //Magnitude
        AssertFloat(5.0f, Vector2Magnitude(a), "Vec2.Magnitude");

        //Normalize
        AssertVec2(Vec2{ 0.6f, 0.8f }, Vector2Normalize(a), "Vec2.Normalize");

        //Dot
        AssertFloat(11.0f, Vector2Dot(a, b), "Vec2.Dot");

        //Edge
        Vec2 zero{ 0.0f, 0.0f };
        AssertVec2(Vec2{ 0.0f, 0.0f }, Vector2Normalize(zero), "Vec2.Normalize.Zero");
    }

    std::cout << "\n === Vec3 ===\n";

    Vec3 a{ 3.0f, 4.0f, 0.0f };
    Vec3 b{ 1.0f, 2.0f, 3.0f };

    //Addition
    AssertVec3(Vec3{ 4.0f,6.0f,3.0f }, VectorAdd(a, b), "Vec.Add");

    //Subtract
    AssertVec3(Vec3{ 2.0f, 2.0f, -3.0f }, VectorSubtract(a, b), "Vec3.Subtract");

    //Magnitude
    AssertFloat(5.0f, VectorMagnitude(a), "Vec3.Magnitude");

    //Normalize
    AssertVec3(Vec3{ 0.6f,0.8f,0.0f }, VectorNormalize(a), "Vec3.Normalize");

    //Dot
    AssertFloat(11.0f, VectorDot(a, b), "Vec3.Dot");

    //Cross
    Vec3 cross = VectorCross(a, b);
    AssertFloat(0.0f, VectorDot(a, cross), "Vec.Cross.Perpendicular A");
    AssertFloat(0.0f, VectorDot(b, cross), "Vec.Cross.Perpendicular B");

    //Edge
    Vec3 zero{ 0.0f, 0.0f, 0.0f };
    AssertVec3(Vec3{ 0.0f, 0.0f, 0.0f }, VectorNormalize(zero), "Vec3.Normalize.Zero");


    //Summary

    std::cout << "\n" << (TestPassed ? "All Test Passed" : "Test Failed") << "\n";
    std::cout << "Total Tests: " << (TestPassed ? "Passed" : " Failed") << "\n";

    std::cin.get();
    return TestPassed ? 0 : 1;

}