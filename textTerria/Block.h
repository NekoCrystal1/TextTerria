#pragma once
#include "StaticCollisionObject.h"
class Block : public StaticCollisionObject {
public:
	Block(COLORREF fillcolor = (COLORREF)0x00FF00, COLORREF linecolor = (COLORREF)0x000000, const Vector2& size = Vector2(32,32), const Vector2& position = Vector2());
	~Block();
	void on_update()override;
	virtual void colide_func(TEntityObject* pTarget) override;
private:
	void initial(const Vector2& size, const Vector2& position);
private:
};