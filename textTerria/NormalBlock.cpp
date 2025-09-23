#include "NormalBlock.h"

#include "AnimationFactory.h"

NormalBlock::NormalBlock(const Vector2& position) : Block(NORMAL_BLOCK_SIZE, position)
{
}

NormalBlock::~NormalBlock()
{
	delete m_pAnimation;
	m_pAnimation = nullptr;
}

bool NormalBlock::initial()
{
	bool ans = Block::initial();
	if (ans)
	{
		m_pAnimation = ANIMATION_FACTORY->tryCreateAnimation(RESOURCES_MANAGER->getImage("TestBlock"), m_pLocalTransform->get_size(), m_pLocalTransform->get_position());
		if (m_pAnimation)
		{
			return true;
		}
	}
	return false;
}
