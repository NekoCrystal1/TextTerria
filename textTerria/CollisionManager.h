#pragma once
#include <vector>
#include <queue>
#include "CollisionBox.h"
//#include "CollisionObject.h"
class CollisionManager{
public:
	static CollisionManager* instance();

	int mod(float x, int mod_num) const;
	//网格对齐函数，返回网格对齐后的世界坐标
	inline Vector2 net_align(const Vector2& pos);
	//返回对象在网格数组中的坐标
	Vector2 get_netvector_pos(const Vector2& pos);
	//CollisionBox* create_collision_box(CollisionType collision_type,Actor* p, const Vector2& size = Vector2(), const Vector2& position = Vector2());
	CollisionBox* create_collision_box(CollisionBox::CollisionType collision_type,Actor* p, Transform* bind_transform);
	void on_update();
	bool check_collision(CollisionBox* dst_box, CollisionBox* src_box);
	void remove_box(CollisionBox* box);
private:
	CollisionManager();
	~CollisionManager();
	
	static CollisionManager* manager;
private:
	//std::vector<CollisionBox*> static_collision_boxes;
	//二维数组作为二维网格碰撞
	std::vector<std::vector<CollisionBox*>> static_collision_boxes;
	int left, right, top, bottom;
	std::vector<CollisionBox*> dynamic_collision_boxes;
	std::queue<CollisionBox*> update_static_collision_boxes;
};