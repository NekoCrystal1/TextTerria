#include "Block.h"
#include "Actor.h"

void Block::initial(const Vector2& size, const Vector2& position)
{
	m_pCollisionComponent->addCollisionBox("BlockBody", CollisionManager::instance()->create_collision_box(
		CollisionBox::CollisionType::Static_Collision, m_pCollisionComponent));
	CollisionBox* collision_box = m_pCollisionComponent->get_collision_box("BlockBody");
	collision_box->set_collision_shape(CollisionBox::CollisionShape::SHAPE_RECTANGLE);
	collision_box->set_collision_src_layer(0x1);
	collision_box->set_collision_func([&]() {
		this->colide_func(collision_box->getTargetEntity());
		});
}

Block::Block(COLORREF fillcolor, COLORREF linecolor, const Vector2& size, const Vector2& position): StaticCollisionObject(size, position)
{
	initial(size, position);
}

Block::~Block()
{
}

void Block::on_update()
{
}	

void Block::colide_func(TEntityObject* pTarget)
{
	Actor* pTargetPawn = dynamic_cast<Actor*>(pTarget);
	if (!pTargetPawn)
	{
		return;
	}
	const Vector2& target_pos = pTargetPawn->getTransform()->get_position();
	const Vector2& target_size = pTargetPawn->getTransform()->get_size();
	const Vector2& pos = m_pLocalTransform->get_position();
	if (target_pos.y + target_size.y >= pos.y && target_pos.y + target_size.y - pTargetPawn->getMovementComponent()->get_velocity().y <= pos.y)
	{
		pTargetPawn->setLocalPosition(target_pos.x, pos.y - target_size.y);
		pTargetPawn->getMovementComponent()->set_velocity_y(0);
	}
}
