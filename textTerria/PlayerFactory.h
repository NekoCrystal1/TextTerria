#pragma once
#include "Player.h"
#include "Singleton.hpp"

#define PLAYER_FACTORY PlayerFactory::instance()
class PlayerFactory : public Singleton<PlayerFactory>
{
	friend Singleton<PlayerFactory>;
private:
	PlayerFactory() = default;
	~PlayerFactory() = default;
public:
	Player* createPlayer(const Vector2& position = Vector2());
};