#include "MovementObject.h"


MovementObject::MovementObject() : TObject(),
max_velocity(16,160), velocity(), acceleration(0,0), fx_acceleration(5), gravity(1), is_free_fall_heighest_y(0)
{
}

MovementObject::~MovementObject()
{
}

void MovementObject::on_update()
{
	velocity += acceleration;
	if (velocity.y + gravity == 0)
		is_free_fall_heighest_y = true;
	else
		is_free_fall_heighest_y = false;
	velocity.y += gravity;
	float x_v1 = velocity.x - fx_acceleration;
	float x_v2 = velocity.x + fx_acceleration;
	
	if(fx_acceleration)
		if (x_v1 > 0 && x_v1 < velocity.x)
			velocity.x = x_v1;
		else if (x_v1 > -fx_acceleration)
			velocity.x = 0;
		else if (x_v2 > 0)
			velocity.x = 0;
		else
			velocity.x = x_v2;

	//限制最大速度
	if (velocity.x > 0 && velocity.x > max_velocity.x)
		velocity.x = max_velocity.x;
	else if (velocity.x < 0 && velocity.x < -max_velocity.x)
		velocity.x = -max_velocity.x;
	if (velocity.y > 0 && velocity.y > max_velocity.y)
		velocity.y = max_velocity.y;
	else if (velocity.y < 0 && velocity.y < -max_velocity.y)
		velocity.y = -max_velocity.y;


	set_position(m_Transform->get_position() + velocity);
}

void MovementObject::set_velocity(const Vector2& velocity)
{
	this->velocity = velocity;
}

void MovementObject::set_velocity(float x, float y)
{
	this->velocity.x = x;
	this->velocity.y = y;
}

void MovementObject::set_velocity_x(float x)
{
	this->velocity.x = x;
}

void MovementObject::set_velocity_y(float y)
{
	this->velocity.y = y;
}

void MovementObject::set_max_velocity(const Vector2& max_vec)
{
	this->max_velocity = max_vec;
}

void MovementObject::set_fx(float fx)
{
	this->fx_acceleration = fx;
}

void MovementObject::set_gravity(float g)
{
	this->gravity = g;
}

const Vector2& MovementObject::get_velocity() const
{
	return velocity;
}

