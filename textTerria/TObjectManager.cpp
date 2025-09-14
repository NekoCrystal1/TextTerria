#include "TObjectManager.h"
TObjectManager* TObjectManager::manager = nullptr;
TObjectManager* TObjectManager::instance()
{
	if (!manager)
		manager = new TObjectManager();
	return manager;
}

//Block* TObjectManager::create_block(COLORREF linecolor, const Vector2& size, const Vector2& position)
//{
//	Block* block = new Block(linecolor, size, position);
//	tobjects.push_back(block);
//	return block;
//}
//Platform* TObjectManager::create_platform(COLORREF linecolor, const Vector2& size, const Vector2& position)
//{
//	Platform* platform = new Platform(linecolor, size, position);
//	tobjects.push_back(platform);
//	return platform;
//}

Block* TObjectManager::create_block(const Vector2& size, const Vector2& position, COLORREF fillcolor, COLORREF linecolor)
{
	Block* block = nullptr;
	if (cur_sence) {
		block = new Block(fillcolor, linecolor, size, position);
		cur_sence->push_element(block);
	}
	return block;
}

Platform* TObjectManager::create_platform(const Vector2& size, const Vector2& position, COLORREF fillcolor, COLORREF linecolor)
{
	Platform* platform = nullptr;
	if (cur_sence) {
		platform = new Platform(size, position);
		cur_sence->push_element(platform);
	}
	return platform;
}

Player* TObjectManager::create_player(const Vector2& size, const Vector2& position)
{
	Player* player = nullptr;
	if (cur_sence) {
		player = new Player(size, position);
		cur_sence->push_element(player);
	}
	return player;
}

Arrow* TObjectManager::create_arrow(Actor* parent, const Vector2& position)
{
	Arrow* arrow = nullptr;
	if (cur_sence) {
		arrow = new Arrow(parent, position);
		cur_sence->push_element(arrow);
	}
	return arrow;
}

void TObjectManager::on_update()
{
}

void TObjectManager::on_render() const
{
}

void TObjectManager::set_output_sence(Sence* sence)
{
	this->cur_sence = sence;
}

TObjectManager::TObjectManager() : cur_sence(nullptr)
{
}

TObjectManager::~TObjectManager()
{
}
