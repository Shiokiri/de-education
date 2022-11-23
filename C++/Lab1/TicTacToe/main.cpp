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
                std::cout << "���벻�Ϸ���" << std::endl;
            }
        }
        std::cout << "��ʤ�ߣ�" << ticTacToe.getWinner() << std::endl;
    }
    return 0;
}