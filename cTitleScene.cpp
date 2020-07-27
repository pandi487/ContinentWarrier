#include "DXUT.h"
#include "cTitleScene.h"
#include "cTimer.h"

cTitleScene::cTitleScene()
{
}

cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	m_mouse = IMAGE->FindImage("Mouse");
	HowToOn = m_CreditOn = false;
	Num = 0;
	m_Timer = new cTimer(0.5);
	m_Title[BG] = IMAGE->FindImage("Title");
	m_Title[PlayOn] = IMAGE->FindImage("PlayOn");
	m_Title[PlayOff] = IMAGE->FindImage("PlayOff");
	//m_Title[OptionOn] = IMAGE->FindImage("OptionOn");
	//m_Title[OptionOff] = IMAGE->FindImage("OptionOff");
	m_Title[ExitOn] = IMAGE->FindImage("ExitOn");
	m_Title[ExitOff] = IMAGE->FindImage("ExitOff");
	m_Title[HowOff] = IMAGE->FindImage("HowOff");
	m_Title[HowOn] = IMAGE->FindImage("HowOn");
	m_Title[CreditOff] = IMAGE->FindImage("CreditOff");
	m_Title[CreditOn] = IMAGE->FindImage("CreditOn");
	m_Title[How] = IMAGE->FindImage("HowTo");
	m_Title[Credit] = IMAGE->FindImage("Credit");
	m_Title[Button] = IMAGE->FindImage("Button");
}

void cTitleScene::Render()
{
	
	RENDER->Render(m_Title[BG], Vec2(0, 0), Vec2(1, 1));
	if (Num == 1)
	{
		RENDER->Render(m_Title[PlayOn], Vec2(15, -180), Vec2(1, 1));
	}
	else
	{
		RENDER->Render(m_Title[PlayOff], Vec2(15, -180), Vec2(1, 1));
	}
	if (Num == 2)
	{
		RENDER->Render(m_Title[HowOn], Vec2(15, -240), Vec2(1, 1));
	}
	else
	{
		RENDER->Render(m_Title[HowOff], Vec2(15, -240), Vec2(1, 1));
	}
	/*
	if (Num == 3)
	{
		RENDER->Render(m_Title[OptionOn], Vec2(17, -300), Vec2(1, 1));
	}
	else
	{
		RENDER->Render(m_Title[OptionOff], Vec2(15, -300), Vec2(1, 1));
	}
	*/
	if (Num == 4)
	{
		RENDER->Render(m_Title[CreditOn], Vec2(17, -300), Vec2(1, 1));
	}
	else
	{
		RENDER->Render(m_Title[CreditOff], Vec2(15, -300), Vec2(1, 1));
	}
	if (Num == 5)
	{
		RENDER->Render(m_Title[ExitOn], Vec2(17, -360), Vec2(1, 1));
	}
	else
	{
		RENDER->Render(m_Title[ExitOff], Vec2(15, -360), Vec2(1, 1));
	}

	if (HowToOn == true)
	{

		RENDER->Render(m_Title[How], Vec2(0, 0), Vec2(1, 1));
		RENDER->Render(m_Title[Button], Vec2(305, 285), Vec2(1, 1));

	}
	if (m_CreditOn == true)
	{
		RENDER->Render(m_Title[Credit], Vec2(0, 0), Vec2(1, 1));
		m_CreditBtnPos = Vec2(220, 170);
		RENDER->Render(m_Title[Button], m_CreditBtnPos, Vec2(1, 1));

	}
	RENDER->Render(m_mouse, Vec2(KEY->GetCurPos().x, -KEY->GetCurPos().y), Vec2(1, 1));

}

void cTitleScene::UIRender()
{
	//IMAGE->TextDraw(to_string(KEY->GetCurPos().x), Vec2(400, 600), 50, true, D3DCOLOR_XRGB(255, 255, 255));

	//IMAGE->TextDraw(to_string(KEY->GetCurPos().y), Vec2(500, 500), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	//IMAGE->TextDraw(to_string(_1.bottom), Vec2(500, 300), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	//IMAGE->TextDraw(to_string(_1.top), Vec2(500, 100), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	//IMAGE->TextDraw(to_string(_1.left), Vec2(400, 200), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	//IMAGE->TextDraw(to_string(_1.right), Vec2(600, 200), 50, true, D3DCOLOR_XRGB(255, 255, 255));
	//IMAGE->TextDraw(to_string(DXUTGetFPS() ), Vec2(1000, 200), 50, true, D3DCOLOR_XRGB(255, 255, 255));

}

void cTitleScene::Release()
{
}

void cTitleScene::IUIRender()
{
}

void cTitleScene::Update()
{
	RECT rt= {0,0,0,0};
	_1 = { long(15 - m_Title[PlayOff]->info.Width / 2),long(210 - m_Title[PlayOff]->info.Height / 2),long(15 + m_Title[PlayOff]->info.Width / 2), long(210 + m_Title[PlayOff]->info.Height / 2)-20 };
	_2 = { long(15 - m_Title[HowOff]->info.Width / 2),long(280 - m_Title[HowOff]->info.Height / 2),long(15 + m_Title[HowOff]->info.Width / 2), long(280 + m_Title[HowOff]->info.Height / 2)-25 };
	//_3 = { long(15 - m_Title[OptionOff]->info.Width / 2),long(320 - m_Title[OptionOff]->info.Height / 2),long(15 + m_Title[OptionOff]->info.Width / 2), long(320 + m_Title[OptionOff]->info.Height / 2) };
	_4 = { long(15 - m_Title[CreditOff]->info.Width / 2),long(320 - m_Title[CreditOff]->info.Height / 2),long(15 + m_Title[CreditOff]->info.Width / 2), long(320 + m_Title[CreditOff]->info.Height / 2) };
	_5 = { long(15 - m_Title[ExitOff]->info.Width / 2),long(380 - m_Title[ExitOff]->info.Height / 2),long(15 + m_Title[ExitOff]->info.Width / 2), long(380+ m_Title[ExitOff]->info.Height / 2) };
	_6 = { long(320 - m_Title[Button]->info.Width / 2),long(-330 - m_Title[Button]->info.Height / 2),long(320 + m_Title[Button]->info.Width / 2), long(-330 + m_Title[Button]->info.Height / 2) };
	_7 = {long(m_CreditBtnPos.x - m_Title[Button]->info.Width / 2),
		long(m_CreditBtnPos.y - m_Title[Button]->info.Height / 2),
		long(m_CreditBtnPos.x + m_Title[Button]->info.Width / 2),
		long(m_CreditBtnPos.y + m_Title[Button]->info.Height / 2) };
	RECT _mouse = { long(KEY->GetCurPos().x - m_mouse->info.Width / 2),long(KEY->GetCurPos().y - m_mouse->info.Height / 2),long(KEY->GetCurPos().x + m_mouse->info.Width / 2),long(KEY->GetCurPos().y + m_mouse->info.Height / 2) };
	if (HowToOn == true)
	{
		if (IntersectRect(&rt,&_6,&_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{
			HowToOn = false;

			}
		}
	}
	else if (m_CreditOn)
	{
		Vec2 m_CurPos = Vec2(KEY->GetCurPos().x, KEY->GetCurPos().y + (WINSIZEY / 2) - 100);
		//printf("Cur Pos = x : %f y : %f\n RECT = %d : %d : %d : %d\n", m_CurPos.x, m_CurPos.y, _7.left, _7.top, _7.right, _7.bottom);
		if (m_CurPos.x<_7.right && m_CurPos.x>_7.left&& m_CurPos.y < _7.bottom && m_CurPos.y > _7.top)
		{
			printf("HE");
			if (KEY->KeyStay(VK_LBUTTON))
			{
			m_CreditOn = false;

			}
		}
	}
	else if (HowToOn == false || m_CreditOn == false)
	{

		switch (Num)
		{
		case 1:
			if (KEY->KeyPress(VK_RETURN))
			{
				SCENE->ChangeScene("cStage1scene");
			}
			break;
		case 2:
			if (KEY->KeyPress(VK_RETURN))
			{
				HowToOn = true;
			}
			break;
		case 3:
			if (KEY->KeyPress(VK_RETURN))
			{

			}
			break;
		case 4:
			if (KEY->KeyPress(VK_RETURN))
			{
				m_CreditOn = true;
			}
			break;
		case 5:
			if (KEY->KeyPress(VK_RETURN))
			{
				exit(1);
			}
			break;
		}
		if (IntersectRect(&rt,&_1,&_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{
				SCENE->ChangeScene("Stage1");

			}
			Num = 1;
		}
		else if (IntersectRect(&rt, &_2, &_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{
				HowToOn = true;

			}
			Num = 2;
		}
		else if (IntersectRect(&rt, &_3, &_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{

			}
			Num = 3;
		}
		else if (IntersectRect(&rt, &_4, &_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{
				m_CreditOn = true;

			}
			Num = 4;
		}
		else if (IntersectRect(&rt, &_5, &_mouse))
		{
			if (KEY->KeyStay(VK_LBUTTON))
			{
				exit(1);
			}
			Num = 5;
		}
	
			if ((KEY->KeyPress(VK_DOWN) && Num == 0) || KEY->KeyPress(VK_UP) && Num == 0)
			{
				SetCursorPos(WINSIZEX / 2 + 55, 730);
			}
			else if (KEY->KeyPress(VK_DOWN) && Num != 5)
			{
				switch (Num)
				{
					
				case 1:
					SetCursorPos(WINSIZEX / 2+ 55, 790);
					break;
				case 2:
					SetCursorPos(WINSIZEX / 2+ 55, 840);
					break;
				case 3:
					SetCursorPos(WINSIZEX / 2+ 55, 910);
					break;
				case 4:
					SetCursorPos(WINSIZEX / 2+ 55, 960);
					break;
				}
				Num++;
			}
			else if (KEY->KeyPress(VK_UP) && Num != 1)
			{
				switch (Num)
				{
				case 2:
					SetCursorPos(WINSIZEX / 2 + 55, 730);
					break;
				case 3:
					SetCursorPos(WINSIZEX / 2 + 55, 800);
					break;
				case 4:
					SetCursorPos(WINSIZEX / 2 + 55, 850);
					break;
				case 5:
					SetCursorPos(WINSIZEX / 2 + 55, 910);
					break;
				}
				Num--;
			}

		

	}
}

