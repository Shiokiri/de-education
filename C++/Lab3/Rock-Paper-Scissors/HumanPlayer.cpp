#include <iostream>

#include "HumanPlayer.h"

void HumanPlayer::generateTrick()
{
	std::cout << "�����ѡ�񣺢�ʯͷ �ڼ��� �۲�" << std::endl;
	int trick;
	std::cin >> trick;
	setTrick(Trick(trick));
}