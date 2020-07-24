#include "DXUT.h"
#include "cEnemyBullet.h"

cEnemyBullet::cEnemyBullet(Vec2 pos)
{
	m_pos = pos;
	SetTag("EnemyBullet");
	m_image = IMAGE->FindImage("EnemyBullet");
	SetPos(pos);
	Damege = 1;
}

cEnemyBullet::~cEnemyBullet()
{
}

void cEnemyBullet::Update()
{
	m_pos.y -= 10.0f;
	SetRect(m_pos, m_image);
	SetRot(0);
	SetPos(m_pos);
	if (OutMap(m_pos))
	{
		ObjDie();
	}
}

void cEnemyBullet::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1));
}

void cEnemyBullet::UIRender()
{
}

void cEnemyBullet::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		obj->ObjDie();
		ObjDel();
	}
}
