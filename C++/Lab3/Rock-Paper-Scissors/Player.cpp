#include "Player.h"

std::string Player::getPlayerName() const {
	return playerName;
}
void Player::setPlayerName(const std::string playerName) {
	this->playerName = playerName;
}
Trick Player::getTrick() const {
	return trick;
}
void Player::setTrick(const Trick trick) {
	this->trick = trick;
}
std::string judgeWinner(const Player* player1, const Player* player2) {
	if (player1->getTrick() == Trick::Rock) {
		if (player2->getTrick() == Trick::Paper) return player2->getPlayerName();
		if (player2->getTrick() == Trick::Scissors) return player1->getPlayerName();
		if (player1->getTrick() == Trick::Rock) return "平局";
	}
	else if (player1->getTrick() == Trick::Scissors) {
		if (player2->getTrick() == Trick::Rock) return player2->getPlayerName();
		if (player2->getTrick() == Trick::Paper) return player1->getPlayerName();
		if (player1->getTrick() == Trick::Scissors) return "平局";
	}
	else if (player1->getTrick() == Trick::Paper) {
		if (player2->getTrick() == Trick::Scissors) return player2->getPlayerName();
		else if (player2->getTrick() == Trick::Rock) return player1->getPlayerName();
		else if (player1->getTrick() == Trick::Paper) return "平局";
	}
	return "ERROR";
}