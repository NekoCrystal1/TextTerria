#include "TComponentObject.h"

TComponentObject::TComponentObject(TEntityObject* pParent) : TObject(pParent->m_pTransform),
m_pParent(pParent)
{
}

TEntityObject* TComponentObject::getParent() const
{
    return m_pParent;
}
