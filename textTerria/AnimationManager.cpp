#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
}
AnimationFactory::~AnimationFactory()
{
}

Animation* AnimationFactory::tryCreateAnimation(IMAGE* pImg, const Vector2& size, const Vector2& position)
{
    Animation* pAns = new Animation(size, position);
    if (!pAns->initial(pImg))
    {
        delete pAns;
        pAns = nullptr;
        return pAns;
    }
    pAns->setParentNode(RENDER_MANAGER->getCruWorkNode());
    return pAns;
}

Animation* AnimationFactory::tryCreateAnimation(Atlas* pAtlas, const Vector2& size, const Vector2& position)
{
    Animation* pAns = new Animation(size, position);
    if (!pAns->initial(pAtlas))
    {
        delete pAns;
        pAns = nullptr;
    }
    return pAns;
}
