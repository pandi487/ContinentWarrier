#include "DXUT.h"
#include "cEnemy2.h"
#include "cTimer.h"
#include "cPlayer.h"
#include "cEnemyBullet.h"
#include "cPlayerBullet.h"

cEnemy2::cEnemy2(Vec2 pos) :m_pos(pos)
{
	SetTag("Enemy2");
	m_image = IMAGE->FindImage("Enemy2");
	m_timer = new cTimer(1);

	SetCollTag("OBB");
	SetPos(m_pos);
	rot = 0.0f;
	HP = 10;
}

cEnemy2::~cEnemy2()
{
}

void cEnemy2::Update()
{
	SetPos(m_pos);

	a += 0.01;
	m_pos.y -= 20.0f * DXUTGetElapsedTime();
	SetRect(m_pos, m_image);

	if (m_timer->Update()) {

		OBJ->AddObj(new cEnemyBullet(m_pos, 0.0f));
		OBJ->AddObj(new cEnemyBullet(m_pos, -45.0f));
		OBJ->AddObj(new cEnemyBullet(m_pos, 45.0f));

	}

}

void cEnemy2::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1), rot, 0.f);

}

void cEnemy2::UIRender()
{
}

void cEnemy2::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		obj->ObjDie();
	}
}
