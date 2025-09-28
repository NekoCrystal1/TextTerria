#include "Platform.h"
#include "Actor.h"
#include "CollisionManager.h"
bool Platform::initial()
{
		CollisionBox* collision_box = CollisionManager::instance()->create_collision_box(
			CollisionBox::CollisionType::Static_Collision, m_pCollisionComponent);
		if (!collision_box)
		{
			//该处无法创建碰撞箱
			return false;
		}
		m_pCollisionComponent->addCollisionBox("PlatformBody", collision_box);
		collision_box->set_collision_shape(CollisionBox::CollisionShape::SHAPE_PLATFORM_LINEAR);
		collision_box->set_collision_src_layer(0x2);
		collision_box->set_collision_func([this, collision_box]() {
			this->colide_func(collision_box->getTargetEntity());
			});
		return true;
}

Platform::Platform(const Vector2& size, const Vector2& position) : StaticCollisionObject(size, position)
{
}

void Platform::colide_func(TEntityObject* pTarget)
{
	Actor* pTargetPawn = dynamic_cast<Actor*>(pTarget);
	if (!pTargetPawn)
	{
		return;
	}
	const Vector2& target_pos = pTargetPawn->getWorldTransform().get_position();
	const Vector2& target_size = pTargetPawn->getWorldTransform().get_size();
	const Vector2& pos = getWorldTransform().get_position();
	//如果碰撞发生，还原对象位置及竖直速度
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - pTargetPawn->getMovementComponent()->get_velocity().y <= pos.y) 
	{
		pTargetPawn->setWorldPosition(Vector2(target_pos.x, pos.y - target_size.y));
		pTargetPawn->getMovementComponent()->set_velocity_y(0);
	}
}