#pragma once
#include <string>
#include <unordered_map>
#include "CollisionObject.h"
#include "MovementObject.h"
#include "AnimationManager.h"
#include "CollisionManager.h"
class Actor : public CollisionObject, public MovementObject {
public:
	Actor(CollisionBox::CollisionType collision_type, const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool is_visiable = true);
	virtual ~Actor();
	virtual void on_update()override;
	virtual void set_position(const Vector2& pos)override;
	virtual void set_position(float x, float y)override;
protected:
	//std::unordered_map<std::string, Animation*> animation_pool;

};