#include "DXUT.h"
#include "cPlayer.h"
#include"cPlayerBullet.h"

cPlayer::cPlayer()
{
	SetTag("Player");
	m_image = IMAGE->FindImage("Player");
	m_pos = Vec2(0, 0);
	m_CurTime = m_OldTime = timeGetTime();
	OBJ->m_player = this;
	HP = 3;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	m_CurTime = timeGetTime();
	SetPos(m_pos);
	SetRot(0);
	SetRect(m_pos, m_image);

	OBJ->AddObj(new cPlayerBullet(m_pos));
	if (KEY->KeyStay(VK_UP) && m_pos.y < WINSIZEY / 2 - 50)
	{
		m_pos.y += 500 * DXUTGetElapsedTime();
	}
	if (KEY->KeyStay(VK_LEFT) && m_pos.x > -610)
	{
		m_pos.x -= 500 * DXUTGetElapsedTime();
	}
	if (KEY->KeyStay(VK_RIGHT) && m_pos.x < 270)
	{
		m_pos.x += 500 * DXUTGetElapsedTime();
	}
	if (KEY->KeyStay(VK_DOWN) && m_pos.y > -WINSIZEY / 2 + 50)
	{
		m_pos.y -= 500 * DXUTGetElapsedTime();
	}


}

void cPlayer::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1, 1));

}

void cPlayer::UIRender()
{
}


void cPlayer::Collision(cObject* obj)
{
	if (obj->GetTag() == "Enemy")
	{
		obj->ObjDie();
		ObjDel();
	}
}
