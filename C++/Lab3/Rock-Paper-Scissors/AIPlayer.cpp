#include <iostream>

#include <ctime>

#include "AIPlayer.h"

void AIPlayer::generateTrick()
{
	srand((unsigned int)time(nullptr));
	int trick = rand() % MAX_TRICK + 1;
	setTrick(Trick(trick));
}