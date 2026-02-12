using UnityEngine;
using DefaultNameSpace;

public class VectorDebugVisualizer : MonoBehaviour
{
    public Transform pointA;
    public Transform pointB;
    public bool showAddition;
    public bool showSubtraction;

    void OnDrawGizmos()
    {
        if (pointA == null || pointB == null) return;
        
        Vec3 a = Vec3.FromUnityVector3(pointA.position);
        Vec3 b = Vec3.FromUnityVector3(pointB.position);
        
        // Point A (red)
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(pointA.position, 0.2f);

        // Point B (blue) 
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(pointB.position, 0.2f);
        
        if (showAddition)
        {
            Vec3 sum = DefaultNameSpace.VectorMath.VectorAdd(a, b);
            Gizmos.color = Color.green;
            Gizmos.DrawWireSphere(sum.ToUnityVector3(), 0.2f);
            Gizmos.DrawLine(Vector3.zero, sum.ToUnityVector3());
        }

        // Subtraction (yellow ray from A)
        if (showSubtraction)
        {
            Vec3 diff = DefaultNameSpace.VectorMath.VectorSubtract(a, b);
            Gizmos.color = Color.yellow;
            Gizmos.DrawRay(pointA.position, diff.ToUnityVector3());
        }
    }
}