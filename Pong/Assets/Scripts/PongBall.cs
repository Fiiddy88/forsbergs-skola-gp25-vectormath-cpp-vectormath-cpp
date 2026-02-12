using UnityEngine;
using DefaultNameSpace;

public class PongBall : MonoBehaviour
{
    public float speed = 5f;
    public float baseSpeed;
    private Vec3 velocity;
    void Start()
    {
        baseSpeed = speed;
        
        velocity = new Vec3(1, 0.5f, 0);
        velocity = VectorMath.VectorNormalize(velocity);
        velocity = VectorMath.VectorScale(velocity, speed);
    }
    
    void Update()
    {
        //Ball Movement
        Vector3 move = velocity.ToUnityVector3() * Time.deltaTime; 
        transform.position += move;
        
        //Scoring Bounds
       
        float x = transform.position.x;

        if (x > 9f || x < -9f)
        {
            ResetBall();
        }
    }

    private void HitWall(Vec3 wallNormal)
    {
        //Reflect
        velocity = VectorMath.VectorReflect(velocity, wallNormal);
        velocity = VectorMath.VectorNormalize(velocity);
        speed = Mathf.Min(speed* 1.1f, 15f);
        velocity = VectorMath.VectorScale(velocity, speed);
        
    }

    void OnTriggerEnter(Collider other)
    {
        Debug.Log($"Ball hit: {other.name}");
        if (other.CompareTag("Paddle"))
        {
            Debug.Log("Paddle collision!");
            //Paddle
            float normalX = (other.transform.position.x < 0f) ? 1f : -1f;
            float offset = transform.position.y - other.transform.position.y;
            float maxOffset = 2f;
            float t = Mathf.Clamp(offset / maxOffset, -1f, 1f);

            Vec3 normal = new Vec3(normalX, t, 0);
            normal = VectorMath.VectorNormalize(normal);
            
            velocity = VectorMath.VectorReflect(velocity, normal);
            velocity = VectorMath.VectorNormalize(velocity);
            speed = Mathf.Min(speed* 1.1f, 15f);
            velocity = VectorMath.VectorScale(velocity, speed);
        }
        else if (other.CompareTag("Wall"))
        {
            Debug.Log("Wall collision!");
            
            float wallY = other.transform.position.y;
            Vec3 wallNormal = (wallY > 0f) ? new Vec3(0, -1, 0) : new Vec3(0, 1, 0);
            velocity = VectorMath.VectorReflect(velocity, wallNormal);
            velocity = VectorMath.VectorNormalize(velocity);
            speed = Mathf.Min(speed * 1.1f, 15f);
            velocity = VectorMath.VectorScale(velocity, speed);
        }
    }

    void ResetBall()
    {
        if (transform.position.x > 0)
            GameManager.Instance.Player2Score();  
        else
            GameManager.Instance.Player1Score();
        
        transform.position = Vector3.zero;
        speed = baseSpeed;
        float dirX = Random.value < 0.5f ? -1f : 1f;
        velocity = new Vec3(dirX, Random.Range(-0.5f, 0.5f), 0);
        velocity = VectorMath.VectorNormalize(velocity);
        velocity = VectorMath.VectorScale(velocity, speed); 
    }

    public void ResetBallWithOriginalSpeed()
    {
        speed = baseSpeed;
        ResetBall();
    }
}
