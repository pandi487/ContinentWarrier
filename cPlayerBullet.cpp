#include "DXUT.h"

#include "cPlayerBullet.h"

cPlayerBullet::cPlayerBullet(Vec2 pos)
{
	SetTag("PlayerBullet");
	m_image = IMAGE->FindImage("PlayerBullet");
	SetPos(pos);
	Damege = 1;

}

cPlayerBullet::~cPlayerBullet()
{

}

void cPlayerBullet::Update()
{
	SetRect(m_pos, m_image);
	SetRot(0);
	SetPos(m_pos);

	if (OutMap(m_pos))
	{
		ObjDie();
	}

}

void cPlayerBullet::Render()
{

	RENDER->Render(m_image, m_pos, Vec2(1, 1));
	printf("½ÇÇà");
}

void cPlayerBullet::UIRender()
{

}

void cPlayerBullet::Collision(cObject* obj)
{
	if (obj->GetTag() == "Emeny")
	{
		obj->ObjDie();
		ObjDel();
	}
}
