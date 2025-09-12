#pragma once
#include "StaticCollisionActor.h"
class Block : public StaticCollisionActor {
public:
	//Block(COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	Block(COLORREF fillcolor = (COLORREF)0x00FF00, COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(32,32), const Vector2& position = Vector2());
	~Block();
	void on_update()override;
	virtual void colide_func(TEntityObject* pTarget) override;
private:
	void initial(const Vector2& size, const Vector2& position);
private:
};