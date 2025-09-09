#pragma once
#include "Sence.h"
#include <vector>
#include "TObject.h"
#include "Block.h"
#include "Platform.h"
#include "Player.h"
#include "Arrow.h"
class TObjectManager {
public:
	static TObjectManager* instance();

	Block* create_block(const Vector2& size = Vector2(32,32), const Vector2& position = Vector2(), COLORREF fillcolor = (COLORREF)0x00FF00, COLORREF linecolor = (COLORREF)0x000000);
	Platform* create_platform(const Vector2& size = Vector2(32,8), const Vector2& position = Vector2(), COLORREF fillcolor = (COLORREF)0x0000FF, COLORREF linecolor = (COLORREF)0x000000);
	Player* create_player(const Vector2& size = Vector2(30, 80), const Vector2& position = Vector2());
	Arrow* create_arrow(Actor* parent, const Vector2& position = Vector2());
	void on_update();
	void on_render()const;
	void set_output_sence(Sence* sence);
private:
	TObjectManager();
	~TObjectManager();
private:
	static TObjectManager* manager;
	Sence* cur_sence;
};