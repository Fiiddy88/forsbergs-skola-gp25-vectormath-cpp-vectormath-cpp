using System.Runtime.InteropServices;
using DefaultNameSpace;

namespace DefaultNameSpace  
{
    public static class VectorMath
    {
        const string DllName = "VectorMathematics";
        
        [DllImport(DllName)]
        public static extern Vec3 VectorAdd(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorSubtract(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern float VectorMagnitude(Vec3 v);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorNormalize(Vec3 v);
        
        [DllImport(DllName)]
        public static extern float VectorDot(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorCross(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorScale(Vec3 v, float s);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorReflect(Vec3 a, Vec3 normal);

        [DllImport(DllName)]
        public static extern Vec3 VectorDistance(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern float VectorDistanceSq(Vec3 a, Vec3 b);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorLerp(Vec3 a, Vec3 b, float t);
        
        [DllImport(DllName)]
        public static extern Vec3 VectorClamp(Vec3 v, float min, float max);

        [DllImport(DllName)]
        public static extern Vec2 Vector2Add(Vec2 a, Vec2 b);
        
        [DllImport(DllName)]
        public static extern Vec2 VectorSubtract(Vec2 a, Vec2 b);
        
        [DllImport(DllName)] 
        public static extern Vec2 Vector2Scale(Vec2 v, float s);

        [DllImport(DllName)] 
        public static extern float Vector2Magnitude(Vec2 v);
        
        [DllImport(DllName)] 
        public static extern Vec2 Vector2Normalize(Vec2 v);
        
        [DllImport(DllName)] 
        public static extern float Vector2Dot(Vec2 a, Vec2 b);
        
        [DllImport(DllName)]
        public static extern Vec2 Vector2Distance(Vec2 a, Vec2 b);
        
        [DllImport(DllName)]
        public static extern float Vector2DistanceSq(Vec2 a, Vec2 b);
        

    }
}