class TicTacToe
{
private:
    char currentPlayer;
    char board[3][3];
public:
    void print();
    char getCurrentPlayer();
    bool isDone();
    char getWinner();
    bool isValidMove(int, int);
    void makeMove(int, int);
    TicTacToe();
};