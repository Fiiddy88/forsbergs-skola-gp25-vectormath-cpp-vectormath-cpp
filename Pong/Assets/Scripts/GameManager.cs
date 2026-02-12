using UnityEngine;
using TMPro;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance;
    public TextMeshProUGUI Player1text;
    public TextMeshProUGUI Player2text;
    public GameObject winPanel;
    public TextMeshProUGUI winText;

    public int player1Score = 0;
    public int player2Score = 0;
    public int pointsToWin = 5;

    void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);
    }

    void Start()
    {
        winPanel.SetActive(false);
        UpdateScoreUI();
    }

    public void Player1Score()
    {
        player1Score++;
        UpdateScoreUI();
        CheckWin("Player 1");
    }

    public void Player2Score()
    {
        player2Score++;
        UpdateScoreUI();
        CheckWin("Player 2");
    }

    public void UpdateScoreUI()
    {
        Player1text.text = player1Score.ToString();
        Player2text.text = player2Score.ToString();
    }

    void CheckWin(string winner)
    {
        if (player1Score >= pointsToWin || player2Score >= pointsToWin)
        {
            winText.text = $"{winner} Wins!";
            winPanel.SetActive(true);
            Time.timeScale = 0;
        }
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.R) && winPanel.activeInHierarchy)
        {
            ResetGame();
        }
    }

    public void ResetGame()
    {
        player1Score = 0;
        player2Score = 0;
        Time.timeScale = 1;
        winPanel.SetActive(false);
        UpdateScoreUI();
        PongBall ball = FindObjectOfType<PongBall>();
        if (ball != null) ball.ResetBallWithOriginalSpeed();
    }
}
