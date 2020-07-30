#include "DXUT.h"
#include "cPlayer.h"
#include "cPlayerBullet.h"
#include "cScore.h"
#include "cTimer.h"
#include "cEnemy.h"
#include "cEnemy2.h"
#include "cEnemy3.h"


INT cPlayer::HP = 100;
cPlayer::cPlayer()
{
	SetTag("Player");
	m_image = IMAGE->FindImage("Player");
	m_pos = Vec2(0, 0);
	m_CurTime = m_OldTime = timeGetTime();
	OBJ->m_player = this;
	m_timer = new cTimer(0.1); 
	z_timer = new cTimer(0.1); 
	m_SkillTimer = new cTimer(10);
	m_bIsSkillOn = FALSE;		// zŰ�Է½ÿ��� ��ų�� ����Ǿ� �ǹǷ� ó�� �ʱ�ȭ�� FALSE�� �صд� (���� TRUE�� �ϸ� ó�� ���ۺ��� ��ų ����)
	m_bIsSkillKeyOn = TRUE;		// ó�� ������ ���۵Ǹ� ��ų ���(z)�� �����ؾ� �ǹǷ� TRUE�� ���� (���� FALSE�� �ϸ� ó�� ���ۺ��� ��ų ��� �Ұ���)
	s_timer = new cTimer(1);
	IsShow = FALSE;

	h_timer = new cTimer(0.1);
	h_SkillTimer = new cTimer(10);
	h_bIsSkillOn = FALSE;
	h_bIsSkillKeyOn = TRUE;
	h_IsShow = FALSE;
	hs_timer = new cTimer(3);
	h_bIsSkillOn = FALSE;
	h_bIsSkillKeyOn = TRUE;
	H_field = 1.f;
	H_y = -380.f;

	H_timer = new cTimer(0.1);
	Hs_timer = new cTimer(3);


}

cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	if (HP <= 0) {
		IMAGE->FindImage("GameOver");//game over�� ��ü
		SCENE->ChangeScene("Title");
		return;
		
	}
	if (SCORE->Score >= 100)
	{
		SCENE->ChangeScene("Title");
		IMAGE->FindImage("GameClear");//game clear�� ��ü
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
	if (KEY->KeyStay(VK_RIGHT) && m_pos.x < 750)
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
	
		field = 1.0f;
		y = -380.0f;
	
		}
		if (m_bIsSkillOn) {		// ��ų�� ������ �� ��
			if (!m_SkillTimer->Update()) {		// Ÿ�̸Ӱ� 10�ʰ� ���� ���� �� (�� 10�� ���� �Ѿ��� ������)
				IsShow = TRUE;
				m_bIsSkillKeyOn = FALSE;		//Ű �Է��� FALSE�� (10�� ������ Ű �Է��� �Ұ����ؾ� �Ǳ� ����)
				if (m_SkillTimer->m_Start < 3) {
					if (z_timer->Update()) {
						OBJ->AddObj(new cPlayerBullet(m_pos, -45.0f));
						OBJ->AddObj(new cPlayerBullet(m_pos, 45.0f));
						OBJ->AddObj(new cPlayerBullet(m_pos, 22.5f));
						OBJ->AddObj(new cPlayerBullet(m_pos, -22.5f));
					}
				}
			}
			else {		// 10�ʰ� ������ ��
				m_bIsSkillOn = FALSE;	//��ų ������ �������ش� ( ���̻� ��ų ������ �ȵ�, �� �ٽ� m_bIsSkillOn�� TRUE�� �Ǹ� ��ų ������ ��)
				m_bIsSkillKeyOn = TRUE;		// ��ų Ű �Է��� ���������. (Ű �Է��� ���������ϱ� ���� zŰ�� �Դ´�)
			}
		}


		/// <summary>
		/// /////////////////////////////////////////////////////////////////////////////////////////
		/// </summary>
		//HP�� ��Ÿ�� Ȯ��
		if (KEY->KeyStay('x') || KEY->KeyStay('X') && h_bIsSkillKeyOn)		// ��ų Ű ����� ������ ��
		{

			h_bIsSkillOn = TRUE;		// ��ų�� ��������ش�.

			h_field = 1.0f;
			Y = -380.0f;

		}
		if (h_bIsSkillOn) {		// ��ų�� ������ �� ��
			if (!h_SkillTimer->Update()) {		// Ÿ�̸Ӱ� 10�ʰ� ���� ���� �� (�� 10�� ���� �Ѿ��� ������)
				h_IsShow = TRUE;
				h_bIsSkillKeyOn = FALSE;		//Ű �Է��� FALSE�� (10�� ������ Ű �Է��� �Ұ����ؾ� �Ǳ� ����)
				if (h_SkillTimer->m_Start < 3) {//��ų ���ӽð�
					if (h_timer->Update()) {
						
						HP += 1;
					}
				}
			}
			else {		// 10�ʰ� ������ ��
				h_bIsSkillOn = FALSE;	//��ų ������ �������ش� ( ���̻� ��ų ������ �ȵ�, �� �ٽ� m_bIsSkillOn�� TRUE�� �Ǹ� ��ų ������ ��)
				h_bIsSkillKeyOn = TRUE;		// ��ų Ű �Է��� ���������. (Ű �Է��� ���������ϱ� ���� zŰ�� �Դ´�)
			}
		}
		if (HP >= 100) {// HP �ִ밪
			HP = 100;
		}
		printf("HP : %d\n", HP);
		printf("Score : %d\n", SCORE->Score);
		
	
}
	

void cPlayer::Render()
{
	RENDER->Render(m_image, m_pos, Vec2(1.0, 1.0));


	RENDER->Render(IMAGE->FindImage("SkillOn"), Vec2(745, -380), Vec2(1.0f, 1.0f));
	if (IsShow){
	RENDER->Render(IMAGE->FindImage("SkillOff"), Vec2(745, y), Vec2(1.0f, field));
	if (s_timer->Update()) {
		field -= 0.1f;
		y -= 5.0f;
	}
	}
	/// <summary>
	/// HP��ų
	/// </summary>
	RENDER->Render(IMAGE->FindImage("HP"), Vec2(600, -380), Vec2(1.0f, 1.0f));
	if (h_IsShow) {
		RENDER->Render(IMAGE->FindImage("SkillOff2"), Vec2(600, Y), Vec2(1.0f, h_field));
		if (hs_timer->Update()) {
			h_field -= 0.1f;//�������� ���ǵ� 0.1f = 
			Y -= 5.0f; //��ũ�� �������� ũ��
		}
	}
	/// <summary>
	/// HP�� ����
	/// </summary>

	RENDER->Render(IMAGE->FindImage("HPbarOff"), Vec2(-730, -380), Vec2(1.0f, 1.0f));
	RENDER->Render(IMAGE->FindImage("HPbarOn"), Vec2(-730, H_y), Vec2(1.0f, H_field));
		if (Hs_timer->Update()) {
			
				//H_y -= 5.0f;
				//H_field -= 0.1f;
			
		}
	

}

void cPlayer::UIRender()
{
	//char m_hp[256];
	//sprintf(m_hp, "%d", HP);
	//IMAGE->TextDraw(str, Vec2(-0, -0), str.size(), true, D3DXCOLOR(0,0,0,1.0f));


}

void cPlayer::Collision(cObject* obj)
{
	//Enemy �� �浹 hp ����
	if (obj->GetTag() == "Enemy") 
	{
		cEnemy* m_Enemy = (cEnemy*)obj;

		H_y -= 5.0f;
		H_field = (float)HP / 100.f;
	
		HP || H_y;
		printf("ü�¹� : %d\n", H_field);
	
	}
}
