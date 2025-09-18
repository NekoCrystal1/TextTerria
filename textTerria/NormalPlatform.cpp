#include "NormalPlatform.h"
#include "AnimationFactory.h"
#include "ResourcesManager.h"
NormalPlatform::NormalPlatform(const Vector2& position) : Platform(Vector2(32, 16), position)
{
}

NormalPlatform::~NormalPlatform()
{
	delete m_pAnimation;
	m_pAnimation = nullptr;
}

bool NormalPlatform::initial()
{
	bool ans = Platform::initial();
	if (ans)
	{
		m_pAnimation = ANIMATION_FACTORY->tryCreateAnimation(RESOURCES_MANAGER->getImage("TestPlatformImg"), m_pLocalTransform->get_position());
		if (m_pAnimation)
		{
			return true;
		}
	}
	return false;
}
