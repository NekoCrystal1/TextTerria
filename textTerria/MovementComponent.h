#pragma once
#include "TComponentObject.h"
#include "Macro.hpp"


class MovementComponent : public TComponentObject {
public:
	MovementComponent(TEntityObject* pParent);
	~MovementComponent() = default;
public:
	virtual void on_update();

	void setAcceleration(const Vector2& value);
	void setAcceleration(float x, float y);
	void setAcceleration_x(float x);
	void setAcceleration_y(float y);
	const Vector2& getAcceleration() const;
	float getAcceleration_x() const;
	float getAcceleration_y() const;

	void set_velocity(const Vector2& velocity);
	void set_velocity(float x, float y);
	void set_velocity_x(float x);
	void set_velocity_y(float y);
	const Vector2& get_velocity()const;

	void set_max_velocity(const Vector2& max_vec);
	void set_fx(float fx);
	void set_gravity(float g);
	bool getIsFreeFallHeighest();
protected:
	Vector2 m_oVelocity;;
	Vector2 m_oMaxVelocity;
	Vector2 m_oAcceleration;
	float fx_acceleration;
	float gravity;
	bool m_bIsFreeFallHeighest;
};