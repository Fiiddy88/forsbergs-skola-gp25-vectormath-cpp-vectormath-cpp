using UnityEngine;
using DefaultNameSpace;

public class VectorMathPong : MonoBehaviour
{
    void Start()
    {
        Vec3 a = new Vec3(1, 0, 0);
        Vec3 b = new Vec3(0, 1, 0);

        Debug.Log(VectorMath.VectorDot(a, b));     
        Debug.Log(VectorMath.VectorCross(a, b));
        Debug.Log(VectorMath.VectorReflect(a, b));
    }
}
