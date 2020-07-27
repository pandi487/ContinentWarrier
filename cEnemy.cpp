#include "DXUT.h"
#include "cEnemy.h"
#include "cTimer.h"
#include "cPlayer.h"
#include "cEnemyBullet.h"
#include "cPlayerBullet.h"
#include "cMultiTexture.h"

cEnemy::cEnemy(Vec2 pos):m_pos(pos)
{
	SetTag("Enemy");
	m_image = IMAGE->FindImage("Enemy");
	m_timer = new cTimer(1);
	
	SetCollTag("OBB");
	SetPos(m_pos);
	rot = 0.0f;
	HP = 10;
}

cEnemy::~cEnemy()
{
}

void cEnemy::Update()
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
		
		
	}

}
//int i = 0;
void cEnemy::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1), rot, 0.f);
	//if (cPlayer::HP <= 0)
	//{
	//	if (i < 6)
	//		i++;
	//	//printf("%d\n", i);

	//	//cTexture* m_image = IMAGE->FindMultiTexture("Effect")->FindImage(i);
	//	//RENDER->Render(m_image, m_pos, Vec2(1.0f, 1.0f));
	//}
}

void cEnemy::UIRender()
{
}

void cEnemy::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		cPlayer* m_Player = (cPlayer*)obj;
		m_Player->HP -= 1;
		ObjDie();
	}
}
