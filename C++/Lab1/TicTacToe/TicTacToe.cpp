#include <iostream>

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    currentPlayer = 'X';
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            board[i][j] = '-';
}
void TicTacToe::print()
{
    std::cout << " ";
    for (int i = 0; i <= 2; i++) std::cout << "  " << i + 1;
    std::cout << std::endl;
    for (int i = 0; i <= 2; i++)
    {
        std::cout << i + 1;
        for (int j = 0; j <= 2; j++)
            std::cout << "  " << board[i][j];
        std::cout << std::endl;
    }
}
char TicTacToe::getCurrentPlayer()
{
    return currentPlayer;
}
bool TicTacToe::isDone() {
    bool noArea = true;
    for (int i = 0; i <= 2; i++)
        for (int j = 0; j <= 2; j++)
            if (board[i][j] == '-')
                noArea = false;
    bool isWin = false;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') isWin = true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') isWin = true;
    for (int i = 0; i <= 2; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') isWin = true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') isWin = true;
    }
    return noArea || isWin;
}
char TicTacToe::getWinner() {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') return board[0][2];
    for (int i = 0; i <= 2; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') return board[0][i];
    }
    return '-';
}
bool TicTacToe::isValidMove(int row, int col)
{
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3)
        return board[row - 1][col - 1] == '-';
    else
        return false;
}
void TicTacToe::makeMove(int row, int col)
{
    board[row - 1][col - 1] = currentPlayer;
    if (currentPlayer == 'X') currentPlayer = 'O';
    else currentPlayer = 'X';
}