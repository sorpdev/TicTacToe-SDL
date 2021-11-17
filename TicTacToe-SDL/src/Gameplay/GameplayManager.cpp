#include "GameplayManager.h"

void GameplayManager::CreatePlayfield()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			const auto fieldGameObject = new GameObject(
				TextureManager::TextureArray[static_cast<int>(TextureManager::Texture::Field)], 400 + (165 * row),
				180 + (164 * col), 165, 164);
			const auto field = new Field(row, col, fieldGameObject);
			m_Fields[row][col] = field;
		}
	}
}

Player GameplayManager::m_CheckWinConditions(std::array<Field*, 3>& winFields)
{
	auto winner = Player::None;

	//Check horizontal win
	for (int i = 0; i < 3; i++)
	{
		if ((m_Fields[i][0]->FieldOwner == m_Fields[i][1]->FieldOwner) && (m_Fields[i][1]->FieldOwner == m_Fields[i][2]
			->FieldOwner))
		{
			if (m_Fields[i][0]->FieldOwner != Player::None)
			{
				winner = CurrentPlayer;
				winFields[0] = m_Fields[i][0];
				winFields[1] = m_Fields[i][1];
				winFields[2] = m_Fields[i][2];
			}
		}
	}

	//Check vertical win
	for (int i = 0; i < 3; i++)
	{
		if ((m_Fields[0][i]->FieldOwner == m_Fields[1][i]->FieldOwner) && (m_Fields[1][i]->FieldOwner == m_Fields[2][i]
			->FieldOwner))
		{
			if (m_Fields[0][i]->FieldOwner != Player::None)
			{
				winner = CurrentPlayer;
				winFields[0] = m_Fields[0][i];
				winFields[1] = m_Fields[1][i];
				winFields[2] = m_Fields[2][i];
			}
		}
	}

	//Check diagonal win
	if ((m_Fields[0][0]->FieldOwner == m_Fields[1][1]->FieldOwner) && (m_Fields[1][1]->FieldOwner == m_Fields[2][2]->
		FieldOwner))
	{
		if (m_Fields[0][0]->FieldOwner != Player::None)
		{
			winner = CurrentPlayer;
			winFields[0] = m_Fields[0][0];
			winFields[1] = m_Fields[1][1];
			winFields[2] = m_Fields[2][2];
		}
	}
	if ((m_Fields[0][2]->FieldOwner == m_Fields[1][1]->FieldOwner) && (m_Fields[1][1]->FieldOwner == m_Fields[2][0]->
		FieldOwner))
	{
		if (m_Fields[0][2]->FieldOwner != Player::None)
		{
			winner = CurrentPlayer;
			winFields[0] = m_Fields[0][2];
			winFields[1] = m_Fields[1][1];
			winFields[2] = m_Fields[2][0];
		}
	}

	return winner;
}

bool GameplayManager::m_CheckDraw()
{
	//Check draw
	bool draw = true;
	for (const auto& m_Field : m_Fields)
	{
		for (const auto field : m_Field)
		{
			if (field->FieldOwner == Player::None)
			{
				draw = false;
			}
		}
	}

	return draw;
}

void GameplayManager::MakeMove(const int row, const int col)
{
	if (CurrentPlayer == Player::None) return;
	auto field = m_Fields[row][col];
	//Check if field has no owner
	if (field->FieldOwner == Player::None)
	{
		//Set current player as owner
		field->FieldOwner = CurrentPlayer;

		//Update field
		//Create player object
		SDL_Texture* playerTexture = TextureManager::TextureArray[static_cast<int>(CurrentPlayer == Player::X
			? TextureManager::Texture::Cross
			: TextureManager::Texture::Circle)];
		constexpr int w = 96;
		constexpr int h = 96;
		const auto playerObject = new GameObject(playerTexture, field->GetGameObject()->X + w / 3,
		                                         field->GetGameObject()->Y + h / 3,
		                                         w, h);
		//Set player object as child
		field->GetGameObject()->SetChild(playerObject);

		//Check win conditions
		std::array<Field*, 3> winFields{};
		Player winner = m_CheckWinConditions(winFields);
		if (winner != Player::None)
		{
			Winner = winner;

			for (int i = 0; i < winFields.size(); i++)
			{
				const Field* winField = winFields[i];
			}

			CurrentPlayer = Player::None;

			return;
		}
		//Check draw
		if (m_CheckDraw())
		{
			//TODO:: Display draw
			CurrentPlayer = Player::None;
			return;
		}

		//Set other player as current player
		CurrentPlayer = (CurrentPlayer == Player::X ? Player::O : Player::X);
	}
}

void GameplayManager::Destroy()
{
	//Delete fields
	for (const auto& m_Field : m_Fields)
	{
		for (const auto field : m_Field)
		{
			delete field;
		}
	}
}
