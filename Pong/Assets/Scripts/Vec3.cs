using System.Runtime.InteropServices;
using UnityEngine;

namespace DefaultNameSpace
{

    [StructLayout((LayoutKind.Sequential))]

    public struct Vec3
    {
        public float x;
        public float y;
        public float z;

        public Vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public static Vec3 FromUnityVector3(Vector3 v)
        {
            return new Vec3(v.x, v.y, v.z);
        }

        public Vector3 ToUnityVector3()
        {
            return new Vector3(x, y, z);
        }

        public override string ToString()
        {
            return string.Format("({0}, {1}, {2})", x, y, z);
        }

    }
}