#include <iostream>
#include <string>
#include <map>

#include "HumanPlayer.h"
#include "AIPlayer.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	HumanPlayer* humanPlayer = new HumanPlayer("玩家");
	AIPlayer* aiPlayer = new AIPlayer("电脑");
	std::map<Trick, std::string> trickString{ {Trick::Rock, "石头"}, {Trick::Scissors, "剪刀"}, {Trick::Paper, "布"} };
	std::map<std::string, int> winningNumber;
	while (true)
	{
		humanPlayer->generateTrick();
		aiPlayer->generateTrick();
		cout << humanPlayer->getPlayerName() << "出了" << trickString[humanPlayer->getTrick()] << ";";
		cout << aiPlayer->getPlayerName() << "出了" << trickString[aiPlayer->getTrick()] << ";";
		std::string winner = judgeWinner(humanPlayer, aiPlayer);
		if (winner == "ERROR") { cout << "出现错误" << endl; break; }
		cout << "本局" << winner << [](std::string winner) -> std::string {
			if (winner == "平局")
				return "";
			else
				return "获胜";
		} (winner) << endl;
		winningNumber[winner] += 1;
		cout << "在玩一轮？（回车键确认，其他键退出）" << endl;
		char c = getchar();
		if (c = getchar() != '\n') break;
	}
	cout << humanPlayer->getPlayerName() << "获胜" << winningNumber[humanPlayer->getPlayerName()] << "局;";
	cout << aiPlayer->getPlayerName() << "获胜" << winningNumber[aiPlayer->getPlayerName()] << "局;";
	cout << "战平" << winningNumber["平局"] << "局" << endl;
	cout << "最终结果：" << [&winningNumber](Player* player1, Player* player2) -> std::string {
		if (winningNumber[player1->getPlayerName()] > winningNumber[player2->getPlayerName()])
			return player1->getPlayerName() + "胜出！";
		else if (winningNumber[player1->getPlayerName()] < winningNumber[player2->getPlayerName()])
			return player2->getPlayerName() + "胜出！";
		else if (winningNumber[player1->getPlayerName()] == winningNumber[player2->getPlayerName()])
			return "平局！";
	} (humanPlayer, aiPlayer) << endl;
	return 0;
}
