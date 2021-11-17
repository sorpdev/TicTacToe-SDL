#pragma once
#include "../Player.h"
#include "../Field.h"
#include "../TextureManager.h"
#include <array>

class GameplayManager
{
private:
	std::array<std::array<Field*, 3>, 3> m_Fields = {};

	Player m_CheckWinConditions(std::array<Field*, 3>& winFields);
	bool m_CheckDraw();
public:
	Player CurrentPlayer = Player::X; //Set X as starting player
	Player Winner = Player::None;

	void CreatePlayfield();
	void MakeMove(int row, int col);
	void Destroy();

	std::array<std::array<Field*, 3>, 3> GetFields() const { return m_Fields; };
};