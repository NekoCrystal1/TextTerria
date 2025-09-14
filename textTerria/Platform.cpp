#include "Platform.h"
#include "Actor.h"
#include "CollisionManager.h"
void Platform::initial(const Vector2& size, const Vector2& position)
{
	m_pCollisionComponent->addCollisionBox("PlatformBody", CollisionManager::instance()->create_collision_box(
	CollisionBox::CollisionType::Static_Collision, m_pCollisionComponent));
	CollisionBox* collision_box = m_pCollisionComponent->get_collision_box("PlatformBody");
	collision_box->set_collision_shape(CollisionBox::CollisionShape::platform_linear);
	collision_box->set_collision_src_layer(0x2);
	collision_box->set_collision_func([&]() {
		this->colide_func(collision_box->getTargetEntity());
		});
}

Platform::Platform(const Vector2& size, const Vector2& position)
{
	initial(size, position);
}

Platform::~Platform()
{
}

void Platform::colide_func(TEntityObject* pTarget)
{
	Actor* pTargetPawn = dynamic_cast<Actor*>(pTarget);
	if (!pTargetPawn)
	{
		return;
	}
	const Vector2& target_pos = pTargetPawn->getTransform()->get_position();
	const Vector2& target_size = pTargetPawn->getTransform()->get_size();
	const Vector2& pos = m_pTransform->get_position();
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - pTargetPawn->getMovementComponent()->get_velocity().y <= pos.y) 
	{
		pTargetPawn->set_position(target_pos.x, pos.y - target_size.y);
		pTargetPawn->getMovementComponent()->set_velocity_y(0);
	}
}