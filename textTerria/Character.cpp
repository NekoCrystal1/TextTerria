#include "Character.h"

Character::Character(const Vector2& size, const Vector2& position, bool is_visiable) : TObject(size, position, is_visiable), 
Actor(CollisionBox::CollisionType::Dynamic_Collision, size, position, is_visiable)
{
}

Character::~Character()
{
}
