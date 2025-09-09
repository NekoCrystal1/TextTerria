#include "Arrow.h"
#include "CollisionManager.h"
Arrow::Arrow(Actor* spawn_scource,const Vector2& position) : TObject(Vector2(48, 27), position, true),
Bullet(spawn_scource, Vector2(48,27),position)
{
	bullet_frame = AnimationManager::instance()->create_frame(0xFF00FF, 0x00FF00, true, position);
	bullet_frame->set_points(std::vector<POINT>({
		{0, 13}, {32, 13}, {32, 0}, {48, 14}, {32, 27}, {32, 15}, {0, 15}
		}));
	bullet_frame->set_position(this->get_transform()->get_position());
	this->set_velocity_x(20);
	this->set_fx(0);
	this->set_gravity(0.1);
	this->life_time_timer.set_end_time(120);
}

Arrow::~Arrow()
{
}
