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
	m_timer = new cTimer(0.1); 
	z_timer = new cTimer(0.1); 
	m_SkillTimer = new cTimer(3);
	m_bIsSkillOn = FALSE;		// z키입력시에만 스킬이 실행되야 되므로 처음 초기화를 FALSE로 해둔다 (만약 TRUE로 하면 처음 시작부터 스킬 가동)
	m_bIsSkillKeyOn = TRUE;		// 처음 게임이 시작되면 스킬 사용(z)이 가능해야 되므로 TRUE로 설정 (만약 FALSE로 하면 처음 시작부터 스킬 사용 불가능)
	HP = 1;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	if (HP <= 0) {
		SCENE->ChangeScene("Title");
	}

	m_CurTime = timeGetTime();
	SetPos(m_pos);
	SetRot(0);
	SetRect(m_pos, m_image);

	if (KEY->KeyStay(VK_UP) && m_pos.y < WINSIZEY / 2 - 50)
	{
		m_pos.y += 500 * DXUTGetElapsedTime();
	}
	if (KEY->KeyStay(VK_LEFT) && m_pos.x > -750)
	{
		m_pos.x -= 500 * DXUTGetElapsedTime();
	}
	if (KEY->KeyStay(VK_RIGHT) && m_pos.x < 280)
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


		// 한번 z키를 눌렀을 시 스킬은 10초간 지속, 지속되는 도중에는 z키를 입력못하게 함
		if (KEY->KeyStay('z') || KEY->KeyStay('Z') && m_bIsSkillKeyOn)		// 스킬 키 사용이 가능할 때
		{
			m_bIsSkillOn = TRUE;		// 스킬을 실행시켜준다.
		}
		if (m_bIsSkillOn) {		// 스킬이 실행중 일 때
			if (!m_SkillTimer->Update()) {		// 타이머가 10초가 되지 않을 때 (즉 10초 동안 총알이 생성됨)
				m_bIsSkillKeyOn = FALSE;		//키 입력은 FALSE로 (10초 동안은 키 입력이 불가능해야 되기 때문)
				if (z_timer->Update()) {
					OBJ->AddObj(new cPlayerBullet(m_pos, -45.0f));
					OBJ->AddObj(new cPlayerBullet(m_pos, 45.0f));
				}
				}
			else {		// 10초가 끝났을 때
				m_bIsSkillOn = FALSE;	//스킬 실행을 해제해준다 ( 더이상 스킬 실행이 안됨, 단 다시 m_bIsSkillOn가 TRUE가 되면 스킬 실행이 됨)
				m_bIsSkillKeyOn = TRUE;		// 스킬 키 입력을 허용해진다. (키 입력이 가능해지니깐 위의 z키가 먹는다)
			}
		}
	
	
}
	

void cPlayer::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(0.8, 0.8));

}

void cPlayer::UIRender()
{
}


void cPlayer::Collision(cObject* obj)
{


}
