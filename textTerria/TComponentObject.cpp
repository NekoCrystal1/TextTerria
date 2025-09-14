#include "TComponentObject.h"

TComponentObject::TComponentObject(TEntityObject* pParent) : TObject(pParent->m_pLocalTransform),
m_pParent(pParent)
{
}

const Transform& TComponentObject::getWorldTransform()
{
    return m_pParent->getWorldTransform();
}

TEntityObject* TComponentObject::getParent() const
{
    return m_pParent;
}
