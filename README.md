Vector Math Pong Game

A Unity 2D Pong implementation built entirely with custom vector mathematics, demonstrating fundamental game development concepts through low-level mathematical operations.

📋 Project Overview

This project implements a complete Pong game using custom-built vector mathematics instead of Unity's built-in Vector2/Vector3 systems. The implementation includes a C++ DLL for vector operations, comprehensive unit testing, and a fully functional Unity game with scoring and win conditions.

🎯 Features Implemented
✅ Custom Vector Math Library (C++ DLL)
• Complete Vec2 operations: Add, Subtract, Scale, Magnitude, Normalize, Dot
• Complete Vec3 operations: Add, Subtract, Scale, Magnitude, Normalize, Dot, Cross
• Pong-specific functions: VectorReflect, VectorLerp

✅ Console Test Project
• Comprehensive unit tests for both Vec2 and Vec3
• Pass/fail output with tolerance-based float comparison
• Edge case testing (zero vector normalization)
• Clear results summary

✅ Unity 2D Pong Game
• Player 1: W/S controls
• Player 2: Up/Down arrow controls
• Ball bounces off all surfaces using custom physics
• Uses ONLY custom vector math (no Unity Vector2/Vector3)
• Ball resets when off-screen with random direction

Advanced Features
✅ Enhanced Vector Operations
• Distance and DistanceSqr for both Vec2 and Vec3
• VectorLerp for smooth interpolation
• VectorClamp for value constraining
• Both Vec2 and Vec3 versions implemented

✅ Complete Win/Lose System
• Score tracking for both players
• First to 5 points wins
• Win message display with UI
• Current scores displayed during gameplay
• R key to restart the game

🔧 Technical Implementation
Vector Mathematics Library

The core mathematics are implemented in C++ as a DLL (VectorMathematics.dll) with the following key functions:

Vec3 Operations:
``cpp
Vec3 VectorAdd(Vec3 a, Vec3 b)           // Vector addition
Vec3 VectorSubtract(Vec3 a, Vec3 b)      // Vector subtraction  
Vec3 VectorScale(Vec3 v, float s)        // Scalar multiplication
float VectorMagnitude(Vec3 v)            // Length calculation
Vec3 VectorNormalize(Vec3 v)             // Unit vector creation
float VectorDot(Vec3 a, Vec3 b)          // Dot product
Vec3 VectorCross(Vec3 a, Vec3 b)         // Cross product
Vec3 VectorReflect(Vec3 v, Vec3 normal)  // Reflection calculation
`

Advanced Operations:
`cpp
float VectorDistance(Vec3 a, Vec3 b)     // Euclidean distance
float VectorDistanceSqr(Vec3 a, Vec3 b)  // Squared distance (optimization)
Vec3 VectorLerp(Vec3 a, Vec3 b, float t) // Linear interpolation
Vec3 VectorClamp(Vec3 v, float min, float max) // Component clamping
`

Game Physics Implementation

Ball Movement:
• Uses normalized direction vectors scaled by speed
• Position updated using: position += velocity * deltaTime
• Speed increases by 10% on each collision (capped at 15f)

Collision Detection:
• Unity's trigger system for collision detection
• Custom reflection calculations using VectorReflect()
• Paddle collisions include spin effect based on hit position

Paddle Physics:
`csharp
// Dynamic normal calculation for paddle hits
float normalX = (paddle.position.x < 0f) ? 1f : -1f;
float offset = ball.position.y - paddle.position.y;
Vec3 normal = new Vec3(normalX, offset_normalized, 0);
velocity = VectorMath.VectorReflect(velocity, normal);
`

🧪 Testing Framework

The console application includes comprehensive testing:

`cpp
void AssertFloat(float expected, float actual, const std::string& testName)
void AssertVec2(Vec2 expected, Vec2 actual, const std::string& testName)  
void AssertVec3(Vec3 expected, Vec3 actual, const std::string& testName)
`

Test Coverage:
• Basic arithmetic operations
• Edge cases (zero vector normalization)
• Cross product perpendicularity verification
• Floating-point precision handling (0.01f tolerance)

🎮 Game Architecture
Key Components:
PongBall.cs - Ball physics and collision handling
PongPaddle.cs - Player input and movement
GameManager.cs - Score tracking and game state
VectorMath.cs - C++ DLL interface
Vec2/Vec3.cs - Custom vector structs with Unity integration

Data Flow:
`
C++ Vector Math → C# DLL Import → Unity Game Objects → Visual Rendering
`

📚 Why Vectors and Matrices Matter in Game Development

Spatial Representation:
• Vectors represent position, velocity, acceleration, and direction in 3D space
• Essential for any object that moves or has spatial relationships
• Enable calculations like distance, angles, and relative positioning

Physics Simulation:
• Collision detection relies heavily on vector mathematics
• Reflection calculations (like ball bouncing) use vector dot products and normalization
• Force application and momentum transfer require vector addition and scaling

Performance Optimization:
• Squared distance calculations avoid expensive square root operations
• Normalized vectors enable consistent directional calculations
• Vector operations are highly optimizable by modern CPUs and GPUs

Animation and Interpolation:
• Linear interpolation (LERP) enables smooth transitions
• Bezier curves and splines rely on vector mathematics
• Camera movements and object transformations use matrix operations

🔍 Implementation Reflection

Technical Skills Developed:
• Mathematical implementation in C++
• DLL creation and C#/C++ interoperability  
• Custom physics engine development
• Unit testing and edge case handling

Game Development Insights:
• Understanding the mathematics behind Unity's built-in systems
• Performance considerations in real-time applications
• The importance of numerical precision in physics calculations
• Separation of concerns between math library and game logic

Challenges Overcome:
DLL Integration: Setting up proper C++/C# interop with extern "C" and marshalling
Floating-Point Precision: Implementing tolerance-based testing for mathematical operations
Physics Accuracy: Ensuring ball reflections feel natural while using only custom math
Performance Optimization: Balancing mathematical accuracy with real-time performance needs

Design Decisions:
• Struct Layout: Used LayoutKind.Sequential for proper memory alignment between C++ and C#
• Error Handling: Zero-vector normalization returns zero vector rather than throwing exceptions
• Speed Ramping: Ball speed increases on collision to maintain gameplay excitement
• Input System: Direct keyboard polling for responsive paddle control

This project demonstrates that understanding the mathematical foundations of game development enables more precise control over game behavior and performance optimization opportunities that higher-level abstractions might obscure.

🚀 How to Run
Build the C++ VectorMathematics` project to generate the DLL
Place the DLL in Unity's Assets/Plugins folder  
Open the Unity project and run the Pong scene
Run the console test application to verify vector math correctness

Controls:
• Player 1: W/S keys
• Player 2: Up/Down arrows
• Restart: R key (when game ends)

Have fun playing!
