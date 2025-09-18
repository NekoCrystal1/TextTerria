#include "NormalBlock.h"

#include "AnimationFactory.h"

NormalBlock::NormalBlock(const Vector2& position) : Block(NORMAL_BLOCK_SIZE, position)
{
}

bool NormalBlock::initial()
{
	bool ans = Block::initial();
	if (ans)
	{
		m_pBlockAnimation = ANIMATION_FACTORY->tryCreateAnimation(RESOURCES_MANAGER->getImage("TestBlock"), m_pLocalTransform->get_position());
		if (m_pBlockAnimation)
		{
			return true;
		}
	}
	return false;
}
