#include "TWorldTransformObject.h"

TWorldTransformObject::TWorldTransformObject(const Transform& oLocalTransform):
TObject(new Transform(oLocalTransform)), m_bIsTransformDirty(true),
m_pWorldTransform(new Transform())
{
}

TWorldTransformObject::TWorldTransformObject(const Vector2& size, const Vector2& position) :
TObject(new Transform(size, position)), m_bIsTransformDirty(true),
m_pWorldTransform(new Transform())
{
}

TWorldTransformObject::~TWorldTransformObject()
{
	delete m_pLocalTransform;
	delete m_pWorldTransform;
}

const Transform& TWorldTransformObject::getWorldTransform()
{
	if (m_bIsTransformDirty)
	{
		updateTransform();
	}
	return *m_pWorldTransform;
}

void TWorldTransformObject::setWorldPosition(const Vector2& newPos)
{
	m_pWorldTransform->set_position(newPos);
}
