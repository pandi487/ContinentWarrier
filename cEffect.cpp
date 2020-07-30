#include "DXUT.h"
#include "cEffect.h"
#include "cTimer.h"

cEffect::cEffect(Vec2 pos)
	:m_pos(pos)
{
	Frame = new cTimer(1);
	m_image[0] = IMAGE->FindImage("Effect1");
	m_image[1] = IMAGE->FindImage("Effect2");
	m_image[2] = IMAGE->FindImage("Effect3");
	m_image[3] = IMAGE->FindImage("Effect4");
	m_image[4] = IMAGE->FindImage("Effect5");
	m_image[5] = IMAGE->FindImage("Effect6");
	m_image[6] = IMAGE->FindImage("Effect7");
	m_image[7] = IMAGE->FindImage("Effect8");
	m_image[8] = IMAGE->FindImage("Effect9");
}

cEffect::~cEffect()
{
}

void cEffect::Update()
{
}

void cEffect::Render()
{
	if (Frame->Update())
	{
		i++;
}
	if (i < 8)
	{
		ObjDie();
	}
	RENDER->Render(m_image[i], m_pos, Vec2(2, 2));
}

void cEffect::UIRender()
{
}

void cEffect::Collision(cObject* obj)
{
}
