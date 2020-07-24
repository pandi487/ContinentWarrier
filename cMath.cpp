#include "DXUT.h"
#include "cMath.h"

cMath::cMath()
{
}

cMath::~cMath()
{
}

float cMath::_atan2(Vec2 v1, Vec2 v2)
{
	return atan2(v2.y - v1.y,v2.x - v2.y);
}
