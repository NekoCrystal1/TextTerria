#pragma once
#include "Animation.h"
#include "StaticCollisionObject.h"

const static Vector2 NORMAL_BLOCK_SIZE = { 32,32 };

class Block : public StaticCollisionObject {
public:
	Block(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~Block();
public:
	virtual bool initial() override;
	void on_update()override;
	virtual void colide_func(TEntityObject* pTarget) override;
};