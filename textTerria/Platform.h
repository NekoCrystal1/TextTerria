#pragma once
#include "AnimationManager.h"
#include "CollisionObject.h"
#include "Player.h"
class Platform : public Actor {
public:
	//Platform(COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	//平台默认大小为长32像素，高8像素
	Platform(COLORREF fillcolor = (COLORREF)0x0000FF, COLORREF linecolor = (COLORREF)0x0000FF, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Platform();
	virtual void on_update();
	virtual void on_render()const;
	virtual void set_position(const Vector2& position) override;
	virtual void set_position(float x, float y) override;
protected:
	void colide_func(MovementObject* target);
private:
	void initial(const Vector2& size, const Vector2& position);
private:
};