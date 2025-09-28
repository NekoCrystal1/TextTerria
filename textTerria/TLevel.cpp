#include "TLevel.h"

TLevel::TLevel() : TEntityObject()
{
}

TLevel::~TLevel()
{
}

void TLevel::on_update()
{
	for (TEntityObject* node : m_vecNextNodes)
	{
		node->on_update();
	}
}
