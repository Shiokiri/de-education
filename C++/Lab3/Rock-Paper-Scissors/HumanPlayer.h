#pragma once

#include <string>

#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer() {}
	HumanPlayer(std::string humanPlayerName) : Player(humanPlayerName) {}
	void generateTrick();
};

