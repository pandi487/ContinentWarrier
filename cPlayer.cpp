#include "DXUT.h"
#include "cPlayer.h"
#include "cPlayerBullet.h"
#include "cTimer.h"

cPlayer::cPlayer()
{
	SetTag("Player");
	m_image = IMAGE->FindImage("Player");
	m_pos = Vec2(0, 0);
	m_CurTime = m_OldTime = timeGetTime();
	OBJ->m_player = this;
	m_timer = new cTimer(3); 
	m_SkillTimer = new cTimer(3);
	HP = 3;
	m_bSkillCheck = TRUE;
	m_isSkillTimer = FALSE;
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
	if (m_timer->Update()) {

		OBJ->AddObj(new cPlayerBullet(m_pos, 0.0f));
	}

	if (KEY->KeyStay('z') || KEY->KeyStay('Z'))
	{
		if (m_bSkillCheck)
			m_isSkillTimer = TRUE;
	}

	if (m_isSkillTimer) {
		if (!m_SkillTimer->Update()) {
			m_bSkillCheck = FALSE;
			OBJ->AddObj(new cPlayerBullet(m_pos, -45.0f));
			OBJ->AddObj(new cPlayerBullet(m_pos, 45.0f));
		}
		else {
			m_isSkillTimer = FALSE;
			m_bSkillCheck = TRUE;
		}

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


}
