#include "Camera.h"
#include "CollisionBox.h"
#include "CollisionComponent.h"
//根据碰撞层级能单独筛选该层级颜色，绘制时可根据包含的层级自动组合
std::vector<COLORREF> CollisionBox::box_colors = std::vector<COLORREF>({
	0x000000,0xEE0000,0x0000EE
	});

CollisionBox::CollisionBox(CollisionType type, CollisionComponent* p, const Transform& oTransform) : TEntityObject(oTransform),
m_pParent(p),collision_type(type), is_valid(true), collision_shape(CollisionShape::null),
collision_src_layer(0), collision_dst_layer(0),
on_collision_func(nullptr), is_collision(false), target(nullptr)
{
}

CollisionBox::~CollisionBox()
{
	m_pTransform = nullptr;
}

void CollisionBox::on_update()
{
	if (is_collision)
		on_collision();
}

void CollisionBox::on_render() const
{
	const Camera& camera = *Camera::instance();
	const Vector2& render_centre = camera.get_render_centre(m_pTransform->get_centre_position());
	const Vector2& render_size = camera.get_render_size(m_pTransform->get_size());
	const Vector2& render_pos = camera.get_render_pos(m_pTransform->get_centre_position(), m_pTransform->get_size());

	switch (collision_shape)
	{
	case CollisionBox::CollisionShape::null:
		break;
	case CollisionBox::CollisionShape::rectangle:
		//setlinecolor(box_colors[collision_src_layer] + box_colors[collision_src_layer]);
		rectangle(render_pos.x, render_pos.y, render_pos.x + render_size.x, render_pos.y + render_size.y);
		break;
	case CollisionBox::CollisionShape::circle:

		break;
	}
}

void CollisionBox::on_collision()
{
	if (on_collision_func) {
		this->on_collision_func();
		this->is_collision = false;
	}
}

void CollisionBox::set_position(const Vector2& position)
{
	TObject::set_position(position);
	
}

void CollisionBox::set_position(float x, float y)
{
	TObject::set_position(x, y);

}

void CollisionBox::set_valid(bool is_valid)
{
	is_valid = is_valid;
}

void CollisionBox::set_collision_shape(CollisionShape shape)
{
	collision_shape = shape;
}

void CollisionBox::set_collision_src_layer(unsigned int src_layer)
{
	this->collision_src_layer = src_layer;
}

void CollisionBox::set_collision_dst_layer(unsigned int dst_layer)
{
	this->collision_dst_layer = dst_layer;
}

void CollisionBox::set_collision_layer(unsigned int src_layer, unsigned int dst_layer)
{
	this->collision_src_layer = src_layer;
	this->collision_dst_layer = dst_layer;
}

void CollisionBox::set_collision_func(std::function<void()> on_collision)
{
	this->on_collision_func = on_collision;
}

void CollisionBox::set_is_collision(bool is_collision)
{
	this->is_collision = is_collision;
}

void CollisionBox::set_target(CollisionBox* target)
{
	this->target = target;
}

const CollisionBox::CollisionShape& CollisionBox::get_collision_shape()const
{
	return collision_shape;
}

const unsigned int CollisionBox::get_collision_src_layer()const
{
	return this->collision_src_layer;
}

const unsigned int CollisionBox::get_collision_dst_layer()const
{
	return this->collision_dst_layer;
}

const Vector2& CollisionBox::get_position() const
{
	return m_pTransform->get_position();
}

const Vector2& CollisionBox::get_centre_position() const
{
	return m_pTransform->get_centre_position();
}

const Vector2& CollisionBox::get_size() const
{
	return m_pTransform->get_size();
}

inline CollisionBox* CollisionBox::get_target() const
{
	return this->target;
}

inline CollisionBox::CollisionType CollisionBox::get_collision_type() const
{
	return this->collision_type;
}

inline TEntityObject* CollisionBox::getParentEntity() const
{
	return this->m_pParent->getParent();
}

inline TEntityObject* CollisionBox::getTargetEntity() const
{
	return this->target->m_pParent->getParent();
}

inline CollisionComponent* CollisionBox::getParentCollisionComponent() const
{
	return this->m_pParent;
}
