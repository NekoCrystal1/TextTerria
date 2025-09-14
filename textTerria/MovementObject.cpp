#include "MovementComponent.h"


MovementComponent::MovementComponent(TEntityObject* pParent) : TComponentObject(pParent),
m_oMaxVelocity(16,160), m_oVelocity(), m_oAcceleration(0,0), fx_acceleration(5), gravity(1), m_bIsFreeFallHeighest(0)
{
}

void MovementComponent::on_update()
{
	m_oVelocity += m_oAcceleration;
	if (m_oVelocity.y + gravity == 0)
		m_bIsFreeFallHeighest = true;
	else
		m_bIsFreeFallHeighest = false;
	m_oVelocity.y += gravity;
	float x_v1 = m_oVelocity.x - fx_acceleration;
	float x_v2 = m_oVelocity.x + fx_acceleration;
	
	if(fx_acceleration)
		if (x_v1 > 0 && x_v1 < m_oVelocity.x)
			m_oVelocity.x = x_v1;
		else if (x_v1 > -fx_acceleration)
			m_oVelocity.x = 0;
		else if (x_v2 > 0)
			m_oVelocity.x = 0;
		else
			m_oVelocity.x = x_v2;

	//限制最大速度
	if (m_oVelocity.x > 0 && m_oVelocity.x > m_oMaxVelocity.x)
		m_oVelocity.x = m_oMaxVelocity.x;
	else if (m_oVelocity.x < 0 && m_oVelocity.x < -m_oMaxVelocity.x)
		m_oVelocity.x = -m_oMaxVelocity.x;
	if (m_oVelocity.y > 0 && m_oVelocity.y > m_oMaxVelocity.y)
		m_oVelocity.y = m_oMaxVelocity.y;
	else if (m_oVelocity.y < 0 && m_oVelocity.y < -m_oMaxVelocity.y)
		m_oVelocity.y = -m_oMaxVelocity.y;


	set_position(m_pLocalTransform->get_position() + m_oVelocity);
}

void MovementComponent::setAcceleration(const Vector2& value)
{
	m_oAcceleration = value;
}

void MovementComponent::setAcceleration(float x, float y)
{
	m_oAcceleration.x = x;
	m_oAcceleration.y = y;
}

void MovementComponent::setAcceleration_x(float x)
{
	m_oAcceleration.x = x;
}

void MovementComponent::setAcceleration_y(float y)
{
	m_oAcceleration.y = y;
}

const Vector2& MovementComponent::getAcceleration() const
{
	return m_oAcceleration;
}

float MovementComponent::getAcceleration_x() const
{
	return m_oAcceleration.x;
}

float MovementComponent::getAcceleration_y() const
{
	return m_oAcceleration.y;
}

void MovementComponent::set_velocity(const Vector2& velocity)
{
	this->m_oVelocity = velocity;
}

void MovementComponent::set_velocity(float x, float y)
{
	this->m_oVelocity.x = x;
	this->m_oVelocity.y = y;
}

void MovementComponent::set_velocity_x(float x)
{
	this->m_oVelocity.x = x;
}

void MovementComponent::set_velocity_y(float y)
{
	this->m_oVelocity.y = y;
}

void MovementComponent::set_max_velocity(const Vector2& max_vec)
{
	this->m_oMaxVelocity = max_vec;
}

void MovementComponent::set_fx(float fx)
{
	this->fx_acceleration = fx;
}

void MovementComponent::set_gravity(float g)
{
	this->gravity = g;
}

bool MovementComponent::getIsFreeFallHeighest()
{
	return m_bIsFreeFallHeighest;
}

const Vector2& MovementComponent::get_velocity() const
{
	return m_oVelocity;
}

