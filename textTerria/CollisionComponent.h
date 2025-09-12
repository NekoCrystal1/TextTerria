#pragma once
#include <string>
#include <unordered_map>
#include "TComponentObject.h"
#include "CollisionBox.h"
#include "CollisionManager.h"
class CollisionComponent : public TComponentObject{
public:
	CollisionComponent(TEntityObject* pParent, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	virtual ~CollisionComponent();
public:
	void addCollisionBox(std::string sBoxName, CollisionBox* pCollisionBox);
	void set_collision_src_layer(std::string sBoxName, unsigned int src_layer);
	void set_collision_dst_layer(std::string sBoxName, unsigned int dst_layer);
	void set_collision_layer(std::string sBoxName, unsigned int src_layer, unsigned int dst_layer);
	void set_collision_shape(std::string sBoxName, CollisionBox::CollisionShape shape);
	void set_collision_func(std::string sBoxName, std::function<void()> on_collision);
	CollisionBox* get_collision_box(std::string sBoxName) const;
protected:
	//使用map存储碰撞箱，可以根据字符串命名查找
	std::unordered_map<std::string, CollisionBox*> m_mapCollisionBoxes;
};