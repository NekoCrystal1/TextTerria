#include "CollisionManager.h"
#include "CollisionComponent.h"
//unenable
int CollisionManager::mod(float x, int mod_num) const
{
	if (x >= 0)
		return (int)x % mod_num;
	else {
		x = -x;

	}
	return 0;
}

inline Vector2 CollisionManager::net_align(const Vector2& pos)
{
	Vector2 ans;
	if ((int)pos.x % 32)
		if (ans.x < 0)
			ans.x = pos.x / 32 - 1;
		else
			ans.x = pos.x / 32;
	else 
		ans.x = pos.x / 32;
	if ((int)pos.y % 32)
		if (ans.y < 0)
			ans.y = pos.y / 32 - 1;
		else
			ans.y = pos.y / 32;
	else
		ans.y = pos.y / 32;
	ans = ans * 32;
	return ans;
}

Vector2 CollisionManager::get_netvector_pos(const Vector2& pos)
{
	Vector2 ans(((int)pos.x) / 32, ((int)pos.y) / 32);
	//检查目标位置是否超出边界
	bool is_extended = false;
	if (ans.x < left) {
		left = ans.x;
		is_extended = true;
	}
	else if (ans.x > right) {
		right = ans.x;
		is_extended = true;
	}
	if (ans.y < top) {
		top = ans.y;
		is_extended = true;
	}
	else if (ans.y > bottom) {
		bottom = ans.y;
		is_extended = true;
	}
	ans = ans - Vector2(left, top);

	//实现网格自动扩展
	if (is_extended || static_collision_boxes.empty()) {
		std::vector<std::vector<CollisionBox*>> new_static_collision_boxes(bottom - top + 1, std::vector<CollisionBox*>(right - left+ 1, nullptr));
		for(std::vector<CollisionBox*>& box_vec : static_collision_boxes)
			for (CollisionBox* box : box_vec) {
				if (box) {
					new_static_collision_boxes[(int)box->get_position().y / 32 - top][(int)box->get_position().x / 32 - left] = box;
				}
			}
		static_collision_boxes.swap(new_static_collision_boxes);
	}
	return ans;
}

CollisionBox* CollisionManager::create_collision_box(CollisionBox::CollisionType collision_type, CollisionComponent* pParent)
{
	CollisionBox* box = nullptr;
	switch (collision_type)
	{
		//静态碰撞箱会自动网格对齐
	case CollisionBox::CollisionType::Static_Collision: 
	{
		Transform boxTransform = pParent->gerLocalTransform();
		Vector2 alignment_pos = net_align(boxTransform.get_position());
		Vector2 netvector_pos = get_netvector_pos(alignment_pos);
		//重叠会导致创建失败
		if (!static_collision_boxes[netvector_pos.y][netvector_pos.x]) {
			boxTransform.set_position(alignment_pos);
			box = new CollisionBox(collision_type, pParent, boxTransform);
			static_collision_boxes[netvector_pos.y][netvector_pos.x] = box;
		}
		break;
	}
	case CollisionBox::CollisionType::Dynamic_Collision:
		box = new CollisionBox(collision_type, pParent, pParent->gerLocalTransform());
		dynamic_collision_boxes.push_back(box);
		break;
	default:
		break;
	}
    return box;
}

void CollisionManager::on_update()
{
	//临时变量记录静态碰撞次数
	int num = 0;
	//分离动态、静态物体减少碰撞检查次数
	for (CollisionBox* box : dynamic_collision_boxes) {
		//使用网格碰撞，动态物体仅检查附近碰撞
		Vector2 netpos_1 = net_align(box->get_position() - 32);
		Vector2 netpos_2 = net_align(box->get_position() + box->get_size() + 32);
		int col_start = netpos_1.x / 32 - left;
		int col_end = netpos_2.x / 32 - left;
		int row_start = netpos_1.y / 32 - top;
		int row_end = netpos_2.y / 32 - top;
		col_end = col_end < static_collision_boxes[0].size() ? col_end : static_collision_boxes[0].size();
		row_end = row_end < static_collision_boxes.size() ? row_end : static_collision_boxes.size();
		for(int i = row_start > 0 ? row_start : 0; i < row_end; i++)
			for(int j = col_start > 0 ? col_start : 0; j < col_end; j++,num++) 
				if (box && static_collision_boxes[i][j] && check_collision(box, static_collision_boxes[i][j])) {
					static_collision_boxes[i][j]->set_is_collision(true);
					static_collision_boxes[i][j]->set_target(box);
					update_static_collision_boxes.push(static_collision_boxes[i][j]);
				}
	}
	//printf("num = %d", num);
	for(int i = 0; i < dynamic_collision_boxes.size(); i++)
		for(int j = i + 1; j < dynamic_collision_boxes.size(); j++)
			if (check_collision(dynamic_collision_boxes[i], dynamic_collision_boxes[j])) {
				dynamic_collision_boxes[j]->set_is_collision(true);
				dynamic_collision_boxes[j]->set_target(dynamic_collision_boxes[i]);
				dynamic_collision_boxes[i]->set_is_collision(true);
				dynamic_collision_boxes[i]->set_target(dynamic_collision_boxes[j]);
			}
	//printf("dynamic_num: %d\n", dynamic_collision_boxes.size());
	for (CollisionBox* i : dynamic_collision_boxes)
		i->on_update();
	while (!update_static_collision_boxes.empty()) {
		//printf("update\t");
		update_static_collision_boxes.front()->on_update();
		update_static_collision_boxes.pop();
	}
	//printf("\n");
	//for (CollisionBox* i : static_collision_boxes)
	//	i->on_update();
}

bool CollisionManager::check_collision(CollisionBox* dst_box, CollisionBox* src_box)
{
	if (dst_box != src_box && dst_box->get_collision_dst_layer() & src_box->get_collision_src_layer()) {
		const Vector2& dst_pos = dst_box->get_position();
		const Vector2& src_pos = src_box->get_position();
		const Vector2& dst_size = dst_box->get_size();
		const Vector2& src_size = src_box->get_size();
		switch (dst_box->get_collision_shape())
		{
		case CollisionBox::CollisionShape::SHAPE_RECTANGLE:
			switch (src_box->get_collision_shape())
			{
			case CollisionBox::CollisionShape::SHAPE_RECTANGLE:
				if ((dst_box->get_centre_position() - src_box->get_centre_position()).absolute() * 2 <
					(dst_box->get_size() + src_box->get_size()) )
					return true;
				break;
			case CollisionBox::CollisionShape::SHAPE_CIRCLE:
				//判断矩形撞圆形
				break;
			case CollisionBox::CollisionShape::SHAPE_PLATFORM_LINEAR:
				//判断矩形撞平台
				if (src_pos.y > dst_pos.y && src_pos.y < dst_pos.y + dst_size.y &&
					dst_pos.x - src_pos.x > -dst_size.x && dst_pos.x - src_pos.x < src_size.x) 
					return true;
				break;
			}
			break;
		case CollisionBox::CollisionShape::SHAPE_CIRCLE:
			switch (src_box->get_collision_shape())
			{
			case CollisionBox::CollisionShape::SHAPE_RECTANGLE:
				break;
			case CollisionBox::CollisionShape::SHAPE_CIRCLE:
				break;
			case CollisionBox::CollisionShape::SHAPE_PLATFORM_LINEAR:
				break;
			}
			break;
		case CollisionBox::CollisionShape::SHAPE_PLATFORM_LINEAR:
			switch (src_box->get_collision_shape())
			{
			case CollisionBox::CollisionShape::SHAPE_RECTANGLE:
				break;
			case CollisionBox::CollisionShape::SHAPE_CIRCLE:
				break;
			case CollisionBox::CollisionShape::SHAPE_PLATFORM_LINEAR:
				break;
			}
			break;
		default:
			break;
		}
	}
	return false;
}

void CollisionManager::remove_box(CollisionBox* box)
{
	switch (box->get_collision_type())
	{
	case CollisionBox::CollisionType::Static_Collision:
		if (static_collision_boxes[(int)box->get_position().y / 32 - top][(int)box->get_position().x / 32 - left] == box)
			delete static_collision_boxes[(int)box->get_position().y / 32 - top][(int)box->get_position().x / 32 - left];
		break;
	case CollisionBox::CollisionType::Dynamic_Collision:
		for (int i = 0; i < dynamic_collision_boxes.size(); i++)
			if (dynamic_collision_boxes[i] == box) {
				dynamic_collision_boxes[i] = dynamic_collision_boxes.back();
				delete box;
				dynamic_collision_boxes.pop_back();
				break;
			}
		break;
	default:
		break;
	}
}

CollisionManager::CollisionManager() : left(0),right(0),top(0),bottom(0)
{
}
