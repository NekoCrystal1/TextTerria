#include "TComponentObject.h"

TComponentObject::TComponentObject(TEntityObject* pParent) : TObject(pParent->m_Transform),
m_pParent(pParent)
{
}
