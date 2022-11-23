#pragma once

#include <string>

enum class Trick { Null, Rock, Scissors, Paper };
constexpr int MAX_TRICK = 3;

class Player
{
private:
	Trick trick;
	std::string playerName;
public:
	Player() : trick(Trick::Null) {};
	Player(std::string playerName) : playerName(playerName) , trick(Trick::Null) {}
	std::string getPlayerName() const;
	void setPlayerName(const std::string playerName);
	Trick getTrick() const;
	void setTrick(const Trick trick);
	friend std::string judgeWinner(const Player* player1, const Player* player2);
	virtual void generateTrick() = 0;
};

