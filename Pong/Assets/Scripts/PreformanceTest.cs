using DefaultNameSpace;
using UnityEngine;

namespace DefaultNameSpace
{
    public class PerformanceTest : MonoBehaviour
    {
        public int Iterations = 100000;

        void Start()
        {
            // Test 1: Custom C++ DLL
            var watch = System.Diagnostics.Stopwatch.StartNew();
            for (int i = 0; i < Iterations; i++)
            {
                Vec3 a = new Vec3(1, 2, 3);
                Vec3 b = new Vec3(4, 5, 6);
                Vec3 result = VectorMath.VectorAdd(a, b);
            }
            watch.Stop();
            Debug.Log($"Custom DLL: {watch.ElapsedMilliseconds}ms for {Iterations:N0} operations");

            // Test 2: Unity Vector3
            watch.Restart();
            for (int i = 0; i < Iterations; i++) 
            {
                Vector3 a = new Vector3(1, 2, 3);
                Vector3 b = new Vector3(4, 5, 6);
                Vector3 result = a + b;
            }
            watch.Stop();
            Debug.Log($"Unity Vector3: {watch.ElapsedMilliseconds}ms for {Iterations:N0} operations");

            // Test 3: Unity.Mathematics
            watch.Restart();
            for (int i = 0; i < Iterations; i++)
            {
                Unity.Mathematics.float3 a = new Unity.Mathematics.float3(1, 2, 3);
                Unity.Mathematics.float3 b = new Unity.Mathematics.float3(4, 5, 6);
                Unity.Mathematics.float3 result = a + b;
            }
            watch.Stop();
            Debug.Log($"Unity.Mathematics: {watch.ElapsedMilliseconds}ms for {Iterations:N0} operations");
        }
    }
}