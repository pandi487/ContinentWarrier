#include "DXUT.h"
#include "cEnemy3.h"
#include "cTimer.h"
#include "cPlayer.h"
#include "cEnemyBullet.h"
#include "cPlayerBullet.h"

cEnemy3::cEnemy3(Vec2 pos) :m_pos(pos)
{
	SetTag("Enemy3");
	m_image = IMAGE->FindImage("Enemy3");
	m_timer = new cTimer(1);
	SetCollTag("OBB");
	SetPos(m_pos);
	rot = 0.0f;
	HP = 10;
}

cEnemy3::~cEnemy3()
{
}

void cEnemy3::Update()
{
	//rot = atan2(OBJ->m_player->GetPos().y - m_pos.y, OBJ->m_player->GetPos().x - m_pos.x);
	//SetRot(D3DXToDegree(rot + 1.5));
	//D3DXVec2Normalize(&pos, &Vec2(m_pos - OBJ->m_player->GetPos()));
	SetPos(m_pos);

	a += 0.01;
	m_pos.y -= 20.0f * DXUTGetElapsedTime();
	SetRect(m_pos, m_image);

	if (m_timer->Update()) {

		OBJ->AddObj(new cEnemyBullet(m_pos, 0.0f));
		OBJ->AddObj(new cEnemyBullet(m_pos, 0.0f));


	}

}

void cEnemy3::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1), rot, 0.f);

}

void cEnemy3::UIRender()
{
}

void cEnemy3::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		obj->ObjDie();
	}
}
