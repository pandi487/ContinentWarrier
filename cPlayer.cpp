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
	m_bIsSkillOn = FALSE;		// z키입력시에만 스킬이 실행되야 되므로 처음 초기화를 FALSE로 해둔다 (만약 TRUE로 하면 처음 시작부터 스킬 가동)
	m_bIsSkillKeyOn = TRUE;		// 처음 게임이 시작되면 스킬 사용(z)이 가능해야 되므로 TRUE로 설정 (만약 FALSE로 하면 처음 시작부터 스킬 사용 불가능)
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
		IMAGE->FindImage("GameOver");//game over로 교체
		SCENE->ChangeScene("Title");
		return;
		
	}
	if (SCORE->Score >= 100)
	{
		SCENE->ChangeScene("Title");
		IMAGE->FindImage("GameClear");//game clear로 교체
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

		// 한번 z키를 눌렀을 시 스킬은 10초간 지속, 지속되는 도중에는 z키를 입력못하게 함
	if (KEY->KeyStay('z') || KEY->KeyStay('Z') && m_bIsSkillKeyOn)		// 스킬 키 사용이 가능할 때
	{

		m_bIsSkillOn = TRUE;		// 스킬을 실행시켜준다.
	
		field = 1.0f;
		y = -380.0f;
	
		}
		if (m_bIsSkillOn) {		// 스킬이 실행중 일 때
			if (!m_SkillTimer->Update()) {		// 타이머가 10초가 되지 않을 때 (즉 10초 동안 총알이 생성됨)
				IsShow = TRUE;
				m_bIsSkillKeyOn = FALSE;		//키 입력은 FALSE로 (10초 동안은 키 입력이 불가능해야 되기 때문)
				if (m_SkillTimer->m_Start < 3) {
					if (z_timer->Update()) {
						OBJ->AddObj(new cPlayerBullet(m_pos, -45.0f));
						OBJ->AddObj(new cPlayerBullet(m_pos, 45.0f));
						OBJ->AddObj(new cPlayerBullet(m_pos, 22.5f));
						OBJ->AddObj(new cPlayerBullet(m_pos, -22.5f));
					}
				}
			}
			else {		// 10초가 끝났을 때
				m_bIsSkillOn = FALSE;	//스킬 실행을 해제해준다 ( 더이상 스킬 실행이 안됨, 단 다시 m_bIsSkillOn가 TRUE가 되면 스킬 실행이 됨)
				m_bIsSkillKeyOn = TRUE;		// 스킬 키 입력을 허용해진다. (키 입력이 가능해지니깐 위의 z키가 먹는다)
			}
		}


		/// <summary>
		/// /////////////////////////////////////////////////////////////////////////////////////////
		/// </summary>
		//HP값 쿨타임 확인
		if (KEY->KeyStay('x') || KEY->KeyStay('X') && h_bIsSkillKeyOn)		// 스킬 키 사용이 가능할 때
		{

			h_bIsSkillOn = TRUE;		// 스킬을 실행시켜준다.

			h_field = 1.0f;
			Y = -380.0f;

		}
		if (h_bIsSkillOn) {		// 스킬이 실행중 일 때
			if (!h_SkillTimer->Update()) {		// 타이머가 10초가 되지 않을 때 (즉 10초 동안 총알이 생성됨)
				h_IsShow = TRUE;
				h_bIsSkillKeyOn = FALSE;		//키 입력은 FALSE로 (10초 동안은 키 입력이 불가능해야 되기 때문)
				if (h_SkillTimer->m_Start < 3) {//스킬 지속시간
					if (h_timer->Update()) {
						
						HP += 1;
					}
				}
			}
			else {		// 10초가 끝났을 때
				h_bIsSkillOn = FALSE;	//스킬 실행을 해제해준다 ( 더이상 스킬 실행이 안됨, 단 다시 m_bIsSkillOn가 TRUE가 되면 스킬 실행이 됨)
				h_bIsSkillKeyOn = TRUE;		// 스킬 키 입력을 허용해진다. (키 입력이 가능해지니깐 위의 z키가 먹는다)
			}
		}
		if (HP >= 100) {// HP 최대값
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
	/// HP스킬
	/// </summary>
	RENDER->Render(IMAGE->FindImage("HP"), Vec2(600, -380), Vec2(1.0f, 1.0f));
	if (h_IsShow) {
		RENDER->Render(IMAGE->FindImage("SkillOff2"), Vec2(600, Y), Vec2(1.0f, h_field));
		if (hs_timer->Update()) {
			h_field -= 0.1f;//내려가는 스피드 0.1f = 
			Y -= 5.0f; //스크롤 내려가는 크기
		}
	}
	/// <summary>
	/// HP바 설정
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
	//Enemy 랑 충돌 hp 빼기
	if (obj->GetTag() == "Enemy") 
	{
		cEnemy* m_Enemy = (cEnemy*)obj;

		H_y -= 5.0f;
		H_field = (float)HP / 100.f;
	
		HP || H_y;
		printf("체력바 : %d\n", H_field);
	
	}
}
