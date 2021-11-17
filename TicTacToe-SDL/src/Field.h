#pragma once
#include "GameObject.h"
#include "Player.h"

class Field
{
private:
	GameObject* m_GameObject{};
public:
	int Row = 0;
	int Col = 0;
	Player FieldOwner = Player::None;

	Field(const int row, const int col, GameObject* gameObject): Col(col)
	{
		this->Row = row;
		this->Col = col;
		m_GameObject = gameObject;
	}

	~Field()
	{
		//Delete game object
		delete m_GameObject;
	}

	GameObject* GetGameObject() const
	{
		return m_GameObject;
	}
};
