#include "Platform.h"
#include "Pawn.h"
#include "CollisionManager.h"
void Platform::initial(const Vector2& size, const Vector2& position)
{
	m_pCollisionComponent->addCollisionBox("PlatformBody", CollisionManager::instance()->create_collision_box(
	CollisionBox::CollisionType::Static_Collision, m_pCollisionComponent));
	collision_box->set_collision_shape(CollisionBox::CollisionShape::platform_linear);
	collision_box->set_collision_src_layer(0x2);
	collision_box->set_collision_func([&]() {
		this->colide_func(collision_box->get_target()->get_parent()->getMovementComponent());
		});
}

Platform::Platform(const Vector2& size, const Vector2& position)
{
	initial(size, position);
}

Platform::~Platform()
{
}

void Platform::on_update()
{
	//CollisionObject::on_update();
}

void Platform::set_position(const Vector2& position)
{
	Actor::set_position(position);
}

void Platform::set_position(float x, float y)
{
	Actor::set_position(x, y);
}

void Platform::colide_func(TEntityObject* pTarget)
{
	Pawn* pTargetPawn = dynamic_cast<Pawn*>(pTarget);
	if (!pTargetPawn)
	{
		return;
	}
	
	const Vector2& target_pos = pTargetPawn->get_transform()->get_position();
	const Vector2& target_size = pTargetPawn->get_transform()->get_size();
	const Vector2& pos = m_Transform->get_position();
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - pTargetPawn->getMovementComponent()->get_velocity().y <= pos.y) 
	{
		pTargetPawn->set_position(target_pos.x, pos.y - target_size.y);
		pTargetPawn->getMovementComponent()->set_velocity_y(0);
	}
}