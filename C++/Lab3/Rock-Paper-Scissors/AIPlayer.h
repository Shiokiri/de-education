#pragma once

#include "Player.h"

class AIPlayer : public Player
{
public:
	AIPlayer() {}
	AIPlayer(std::string AIPlayerName) : Player(AIPlayerName) {}
	void generateTrick();
};

