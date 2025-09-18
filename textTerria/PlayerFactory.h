#pragma once
#include "Player.h"
#include "Singleton.hpp"
class PlayerFactory : public Singleton<PlayerFactory>
{
	friend Singleton<PlayerFactory>;
private:
	PlayerFactory() = default;
	~PlayerFactory() = default;
public:
	Player* createPlayer(const Vector2& position = Vector2());
};