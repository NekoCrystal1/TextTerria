#include "NormalPlatform.h"
#include "AnimationFactory.h"
#include "ResourcesManager.h"
NormalPlatform::NormalPlatform(const Vector2& position) : Platform(Vector2(32, 16), position), m_pPlatformAnimation(nullptr)
{
}

bool NormalPlatform::initial()
{
	bool ans = Platform::initial();
	if (ans)
	{
		m_pPlatformAnimation = ANIMATION_FACTORY->tryCreateAnimation(RESOURCES_MANAGER->getImage("TestPlatformImg"), m_pLocalTransform->get_position());
		if (m_pPlatformAnimation)
		{
			return true;
		}
	}
	return false;
}
