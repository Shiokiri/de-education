#include <iostream>

#include "TicTacToe.h"

int main()
{
    TicTacToe ticTacToe;
    while (1)
    {
        ticTacToe = TicTacToe();
        ticTacToe.print();
        while (ticTacToe.isDone() == false)
        {
            int row, col;
            std::cin >> row >> col;
            if (ticTacToe.isValidMove(row, col) == true)
            {
                ticTacToe.makeMove(row, col);
                ticTacToe.print();
            }
            else
            {
                std::cout << "输入不合法！" << std::endl;
            }
        }
        std::cout << "获胜者：" << ticTacToe.getWinner() << std::endl;
    }
    return 0;
}