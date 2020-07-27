#include "DXUT.h"
#include "cTimer.h"

cTimer::cTimer(FLOAT Del)
	:m_Del(Del)
{
}

BOOL cTimer::Update()
{
	m_Start += DXUTGetElapsedTime();
	if (m_Start > m_Del)
	{
		m_Start = 0.f;
		return TRUE;
	}
	return FALSE;
}