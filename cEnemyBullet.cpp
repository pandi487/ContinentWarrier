#include "DXUT.h"
#include "cEnemyBullet.h"
#include "cPlayer.h"

cEnemyBullet::cEnemyBullet(Vec2 pos, FLOAT theta)
{
	m_pos = pos;
	SetTag("EnemyBullet");
	m_image = IMAGE->FindImage("EnemyBullet");
	SetPos(pos);
	Damege = 1;
	m_pos = pos;
	this->theta = theta;

}

cEnemyBullet::~cEnemyBullet()
{
}

void cEnemyBullet::Update()
{
	m_pos.y -= sinf(D3DXToRadian(theta + 90.0f)) * 5.0f;
	m_pos.x -= cosf(D3DXToRadian(theta + 90.0f)) * 5.0f;

	//m_pos.y -= 10.0f;
	SetRect(m_pos, m_image);
	//SetRot(0);
	SetPos(m_pos);
	if (OutMap(m_pos))
	{
		ObjDie();
	}

}

void cEnemyBullet::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1.0f, 1.0f), theta, 0.f);
}

void cEnemyBullet::UIRender()
{
}

void cEnemyBullet::Collision(cObject* obj)
{
	if (obj->GetTag() == "Player")
	{
		cPlayer* m_Player = (cPlayer*)obj;
		m_Player->HP -= Damege;
		if (m_Player->HP <= 0)
			obj->ObjDie();
		ObjDie();
	}
}

BOOL cEnemyBullet::IsMapOut()
{
	if (m_pos.x < -610 || m_pos.x > 270
		|| m_pos.y > WINSIZEY / 2 - 50 || m_pos.y < -WINSIZEY / 2 + 50) {
		return TRUE;
	}
	return FALSE;
}
