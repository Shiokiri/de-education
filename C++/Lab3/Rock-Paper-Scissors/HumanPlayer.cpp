#include <iostream>

#include "HumanPlayer.h"

void HumanPlayer::generateTrick()
{
	std::cout << "请玩家选择：①石头 ②剪刀 ③布" << std::endl;
	int trick;
	std::cin >> trick;
	setTrick(Trick(trick));
}