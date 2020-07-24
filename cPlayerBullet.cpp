#include "DXUT.h"
#include "cPlayerBullet.h"

int cPlayerBullet::Damege = 1;
cPlayerBullet::cPlayerBullet(Vec2 pos, FLOAT theta)
{
	this->theta = theta;
	SetTag("PlayerBullet");
	m_image = IMAGE->FindImage("PlayerBullet");
	SetPos(pos);

	m_pos = pos;
}

cPlayerBullet::~cPlayerBullet()
{
}

void cPlayerBullet::Update()
{
	m_pos.y += sinf(D3DXToRadian(theta + 90.0f)) * 50.0f;
	m_pos.x += cosf(D3DXToRadian(theta + 90.0f)) * 50.0f;

	SetRect(m_pos, m_image);
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
		//obj->ObjDie();
		ObjDie();
	}

}
