#pragma once
#include <vector>
#include <easyx.h>
#include <functional>
#include "TEntityObject.h"
class CollisionComponent;
class CollisionBox : public TEntityObject{
public:
	enum class CollisionType
	{
		Static_Collision,
		Dynamic_Collision,
	};
public:
	//暂时仅使用AABB矩形碰撞,以及平台线性碰撞
	enum class CollisionShape
	{
		SHAPE_NULL,
		SHAPE_RECTANGLE,			//position为左上坐标,size + position为右下坐标
		SHAPE_CIRCLE,				//position为圆左上坐标,position + size * 0.5f 为圆心坐标,size的x是半径(size.y应该与size.x相等否则会产生碰撞偏移)
		SHAPE_PLATFORM_LINEAR,	//平台线性碰撞
	};
	static std::vector<COLORREF> box_colors;
public:
	//需要设置碰撞源、碰撞目标、形状
	CollisionBox(CollisionType type, CollisionComponent* p, const Transform& transform);
	~CollisionBox();
	void on_update();
	void on_render()const ;
	void on_collision();
	virtual void set_position(const Vector2& position) override;
	virtual void set_position(float x, float y) override;
	//对位置进行网格对齐
	void set_valid(bool is_valid);
	void set_collision_shape(CollisionShape shape);
	void set_collision_src_layer(unsigned int src_layer);
	void set_collision_dst_layer(unsigned int dst_layer);
	void set_collision_layer(unsigned int src_layer, unsigned int dst_layer);
	void set_collision_func(std::function<void()> on_collision);
	void set_is_collision(bool is_collision = true);
	void set_target(CollisionBox* target);
	const CollisionShape& get_collision_shape()const;
	const unsigned int get_collision_src_layer()const;
	const unsigned int get_collision_dst_layer()const;
	const Vector2& get_position()const;
	const Vector2& get_centre_position()const;
	const Vector2& get_size()const;
	CollisionBox* get_target() const;
	CollisionComponent* getParentCollisionComponent()const;
	CollisionType get_collision_type() const;
	TEntityObject* getParentEntity() const;
	TEntityObject* getTargetEntity() const;
protected:
	bool is_valid;
	CollisionShape collision_shape;
	//碰撞层级按位运算
	//第0位：方块实体碰撞；第1位：平台实体碰撞
	//作为被碰撞对象可接受的碰撞
	unsigned int collision_src_layer;
	//作为泥头车可创的对象
	unsigned int collision_dst_layer;
	std::function<void()> on_collision_func;
	bool is_collision;
	CollisionComponent* m_pParent;
	CollisionBox* target;
	CollisionType collision_type;
};