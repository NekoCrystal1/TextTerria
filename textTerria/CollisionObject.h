//#pragma once
//#include "TEntityObject.h"
//#include "CollisionBox.h"
//#include "CollisionManager.h"
//class Actor;
//class CollisionObject : public TObject{
//protected:
//	CollisionObject(CollisionBox::CollisionType collision_type, Actor* p,
//		const Vector2& size = Vector2(), const Vector2& position = Vector2(), bool is_visiable = false);
//	virtual ~CollisionObject();
//public:
//	//碰撞箱更新在碰撞管理器中处理
//	virtual void on_update();
//	virtual void set_position(const Vector2& position) override;
//	virtual void set_position(float x, float y) override;
//	void set_collision_src_layer(unsigned int src_layer);
//	void set_collision_dst_layer(unsigned int dst_layer);
//	void set_collision_layer(unsigned int src_layer, unsigned int dst_layer);
//	void set_collision_shape(CollisionBox::CollisionShape shape);
//	void set_collision_func(std::function<void()> on_collision);
//	CollisionBox* get_collision_box();
//protected:
//	CollisionBox* collision_box;
//};