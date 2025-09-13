#include "CollisionComponent.h"
CollisionComponent::CollisionComponent(TEntityObject* pParent, const Vector2& size, const Vector2& position) :
	TComponentObject(pParent)
{
}

CollisionComponent::~CollisionComponent()
{
	for (std::pair<std::string, CollisionBox*> i : m_mapCollisionBoxes)
	{
		i.second->setCanBeDeleted();
	}
}

void CollisionComponent::addCollisionBox(std::string sBoxName, CollisionBox* pCollisionBox)
{
	m_mapCollisionBoxes.insert(std::pair<std::string, CollisionBox*>(sBoxName, pCollisionBox));
}

void CollisionComponent::set_collision_src_layer(std::string sBoxName, unsigned int src_layer)
{
	CollisionBox* collision_box = get_collision_box(sBoxName);
	collision_box->set_collision_src_layer(src_layer);
}

void CollisionComponent::set_collision_dst_layer(std::string sBoxName, unsigned int dst_layer)
{
	get_collision_box(sBoxName)->set_collision_dst_layer(dst_layer);
}

void CollisionComponent::set_collision_layer(std::string sBoxName, unsigned int src_layer, unsigned int dst_layer)
{
	get_collision_box(sBoxName)->set_collision_layer(src_layer, dst_layer);
}

void CollisionComponent::set_collision_shape(std::string sBoxName, CollisionBox::CollisionShape shape)
{
	get_collision_box(sBoxName)->set_collision_shape(shape);
}

void CollisionComponent::set_collision_func(std::string sBoxName, std::function<void()> on_collision)
{
	get_collision_box(sBoxName)->set_collision_func(on_collision);
}

CollisionBox* CollisionComponent::get_collision_box(std::string sBoxName) const
{
	auto pair = m_mapCollisionBoxes.find(sBoxName);
	if (pair == m_mapCollisionBoxes.end())
	{
		return nullptr;
	}
	return pair->second;
}

