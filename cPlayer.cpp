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
	m_bIsSkillOn = FALSE;		// zŰ�Է½ÿ��� ��ų�� ����Ǿ� �ǹǷ� ó�� �ʱ�ȭ�� FALSE�� �صд� (���� TRUE�� �ϸ� ó�� ���ۺ��� ��ų ����)
	m_bIsSkillKeyOn = TRUE;		// ó�� ������ ���۵Ǹ� ��ų ���(z)�� �����ؾ� �ǹǷ� TRUE�� ���� (���� FALSE�� �ϸ� ó�� ���ۺ��� ��ų ��� �Ұ���)
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

	// �ѹ� zŰ�� ������ �� ��ų�� 10�ʰ� ����, ���ӵǴ� ���߿��� zŰ�� �Է¸��ϰ� ��
	if (KEY->KeyStay('z') || KEY->KeyStay('Z') && m_bIsSkillKeyOn)		// ��ų Ű ����� ������ ��
	{
		m_bIsSkillOn = TRUE;		// ��ų�� ��������ش�.
	}
	if (m_bIsSkillOn) {		// ��ų�� ������ �� ��
		if (!m_SkillTimer->Update()) {		// Ÿ�̸Ӱ� 10�ʰ� ���� ���� �� (�� 10�� ���� �Ѿ��� ������)
			m_bIsSkillKeyOn = FALSE;		//Ű �Է��� FALSE�� (10�� ������ Ű �Է��� �Ұ����ؾ� �Ǳ� ����)
			OBJ->AddObj(new cPlayerBullet(m_pos, -45.0f));
			OBJ->AddObj(new cPlayerBullet(m_pos, 45.0f));
		}
		else {		// 10�ʰ� ������ ��
			m_bIsSkillOn = FALSE;	//��ų ������ �������ش� ( ���̻� ��ų ������ �ȵ�, �� �ٽ� m_bIsSkillOn�� TRUE�� �Ǹ� ��ų ������ ��)
			m_bIsSkillKeyOn = TRUE;		// ��ų Ű �Է��� ���������. (Ű �Է��� ���������ϱ� ���� zŰ�� �Դ´�)
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
