#include "TLevel.h"

TLevel::TLevel() : TObject(new Transform()), TNodeInterface(nullptr)
{
}

TLevel::~TLevel()
{
}
