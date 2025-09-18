#pragma once
#include "TEntityObject.h"
#include "CollisionComponent.h"
class StaticCollisionObject : public TEntityObject
{
public:
	StaticCollisionObject(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	~StaticCollisionObject();
public:
	CollisionComponent* getCollisionComponent();
	//需要创建碰撞箱时，根据是否创建成功返回true/false
	virtual bool initial();
protected:
	virtual void colide_func(TEntityObject* target);
protected:
	CollisionComponent* m_pCollisionComponent;
};
