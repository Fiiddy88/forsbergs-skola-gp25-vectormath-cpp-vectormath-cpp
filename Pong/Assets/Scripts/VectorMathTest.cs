using UnityEngine;
using DefaultNameSpace;

namespace DefaultNameSpace
{
    public class VectorMathTest : MonoBehaviour
    {
        void Start()
        {
            Debug.Log("Testing VectorMath DLL");

            Vec3 a = new Vec3(1, 2, 3);
            Vec3 b = new Vec3(2, 3, 4);

            Vec3 result = VectorMath.VectorAdd(a, b);
            
            Debug.Log($"Vector add: {a} + {b} = {result}");


            Vector3 resultUnityVector = result.ToUnityVector3();
            Debug.Log(resultUnityVector);
            
            
            Debug.Log("Test move object to result position");
            var go = GameObject.CreatePrimitive(PrimitiveType.Cube);
            Debug.Log($"TEst object starting position: {go.transform.position}");
            go.transform.position = result.ToUnityVector3();
            Debug.Log($"TEst object new position: {go.transform.position}");
        }
    }
}