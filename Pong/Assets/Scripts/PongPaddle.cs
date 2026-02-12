using UnityEngine;
using UnityEngine.InputSystem;

public class PongPaddle : MonoBehaviour
{
    public float speed = 8f;
    public bool isLeftPaddle = true;

    private PlayerInput playerInput;
    private InputAction moveAction;

    void Awake()
    {
        playerInput = GetComponent<PlayerInput>();
        if (playerInput != null)
            moveAction = playerInput.actions["Move"];
    }

    void Update()
    {
        float input = 0f;

        if (isLeftPaddle)
        {
            // W/S
            if (Keyboard.current.wKey.isPressed) input = 1f;
            if (Keyboard.current.sKey.isPressed) input = -1f;
        }
        else
        {
            // Up/Down arrows
            if (Keyboard.current.upArrowKey.isPressed) input = 1f;
            if (Keyboard.current.downArrowKey.isPressed) input = -1f;
        }

        Vector3 move = new Vector3(0, input * speed * Time.deltaTime, 0);
        transform.position += move;

        // Playfield Clamp
        float clampedY = Mathf.Clamp(transform.position.y, -3.5f, 3.5f);
        transform.position = new Vector3(transform.position.x, clampedY, 0);
    }
}