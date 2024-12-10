using UnityEngine;

public class MoveAndFall : MonoBehaviour
{
    public float moveSpeed = 5f; 
    public float minX = -5f; 
    public float maxX = 5f; 
    public float fixedY = 11f;
    public float fixedZ = 0.9f;

    private Rigidbody rb;
    private bool isMoving = true; 

    void Start()
    {
        rb = GetComponent<Rigidbody>();
        transform.position = new Vector3(0, fixedY, fixedZ);
    }

    void Update()
    {

        if (isMoving)
        {
            transform.Translate(Vector3.right * moveSpeed * Time.deltaTime);

            if (transform.position.x < minX || transform.position.x > maxX)
            {
                moveSpeed *= -1;
            }
            transform.position = new Vector3(transform.position.x, fixedY, fixedZ);
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            isMoving = false;
            rb.linearVelocity = Vector3.zero;
            rb.useGravity = true;
        }
    }
}