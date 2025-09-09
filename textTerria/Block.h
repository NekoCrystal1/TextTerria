#pragma once
#include "Actor.h"
#include "AnimationManager.h"
class Block : public Actor {
public:
	//Block(COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	Block(COLORREF fillcolor = (COLORREF)0x00FF00, COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(32,32), const Vector2& position = Vector2());
	~Block();
	void on_update()override;
	void on_render()const override;
	virtual void set_position(const Vector2& position)override;
protected:
	void colide_func(MovementObject* target);
private:
	void initial(const Vector2& size, const Vector2& position);
private:
	Animation::Frame* frame;
};