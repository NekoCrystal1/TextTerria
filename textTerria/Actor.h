#pragma once
#include <string>
#include <unordered_map>
#include "TEntityObject.h"
#include "MovementComponent.h"
#include "AnimationManager.h"
#include "CollisionManager.h"
class Actor : public TEntityObject{
public:
	Actor(const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~Actor();
	virtual void on_update() override;
	MovementComponent* getMovementComponent();
protected:
	MovementComponent* m_pMovementComponent;
	CollisionBox* collision_box;
};