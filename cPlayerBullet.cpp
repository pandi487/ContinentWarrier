#include "DXUT.h"
#include "cPlayerBullet.h"
#include "cEnemy.h"
#include "cScore.h"

cPlayerBullet::cPlayerBullet(Vec2 pos, FLOAT theta)
{
	this->theta = theta;
	SetTag("PlayerBullet");
	m_image = IMAGE->FindImage("PlayerBullet");
	SetPos(pos);
	Damege = 1;
	m_pos = pos;
}

cPlayerBullet::~cPlayerBullet()
{
}

void cPlayerBullet::Update()
{

	m_pos.y += sinf(D3DXToRadian(theta + 90.0f)) * 20.0f;
	m_pos.x += cosf(D3DXToRadian(theta + 90.0f)) * 20.0f;

	SetRect(m_pos, m_image);
	SetPos(m_pos);
	
	if (IsMapOut()) {
		ObjDie();
	}
}

void cPlayerBullet::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1.0f, 1.0f), theta, 0.f);

}

void cPlayerBullet::UIRender()
{
}

void cPlayerBullet::Collision(cObject* obj)
{
	if (obj->GetTag() == "Enemy")
	{
		
		cEnemy* m_Enemy = (cEnemy*)obj;
		m_Enemy->HP -= Damege; 
		if (m_Enemy->HP <= 0) {
			obj->ObjDie();
			SCORE->Score += 100;
		}
		ObjDie();
	}
	if (obj->GetTag() == "Enemy2")
	{
		cEnemy* m_Enemy = (cEnemy*)obj;
		m_Enemy->HP -= Damege;
		if (m_Enemy->HP <= 0) {
			obj->ObjDie();
			SCORE->Score += 100;
		}
		ObjDie();
	}
	if (obj->GetTag() == "Enemy3")
	{
		cEnemy* m_Enemy = (cEnemy*)obj;
		m_Enemy->HP -= Damege;
		if (m_Enemy->HP <= 0){
			obj->ObjDie();
			SCORE->Score += 100;
		}
		ObjDie();
	}
}

BOOL cPlayerBullet::IsMapOut()
{
	if (m_pos.x < -800 || m_pos.x > 800
		|| m_pos.y > WINSIZEY / 2 - 10 || m_pos.y < -WINSIZEY / 2 + 10) {
		return TRUE;
	}
	return FALSE;
}
