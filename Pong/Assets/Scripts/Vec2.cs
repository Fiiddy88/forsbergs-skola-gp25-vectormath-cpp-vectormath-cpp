using System.Runtime.InteropServices;
using UnityEngine;

namespace DefaultNameSpace
{

    [StructLayout((LayoutKind.Sequential))]
    public struct Vec2
    {
        public float x, y;

        public Vec2(float x, float y)
        {
            this.x = x;
            this.y = y;
        }

        public static Vec2 FromUnityVector2(UnityEngine.Vector2 v)
        {
            return new Vec2(v.x, v.y);
        }

        public UnityEngine.Vector2 ToUnityVector2()
        {
            return new UnityEngine.Vector2(x, y);
        }
    }
}