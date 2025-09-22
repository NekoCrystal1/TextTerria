#pragma once
#include "Animation.h"
#include "TEntityObject.h"
#include "CollisionComponent.h"
class StaticCollisionObject : public TEntityObject
{
public:
	StaticCollisionObject(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~StaticCollisionObject();
public:
	CollisionComponent* getCollisionComponent();
	//需要创建碰撞箱时，根据是否创建成功返回true/false
	virtual bool initial();
	virtual void setLocalPosition(const Vector2& newPos)override;
	virtual void setLocalPosition(float x, float y)override;
protected:
	virtual void colide_func(TEntityObject* target);
protected:
	CollisionComponent* m_pCollisionComponent;
	//该指针指向当前使用的动画，在具体类中被创建和释放，对其变换的默认修改可以使用该类中的宏修改
	Animation* m_pAnimation;
};
