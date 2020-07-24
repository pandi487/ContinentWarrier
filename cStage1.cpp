#include "DXUT.h"
#include "cStage1.h"
#include"cStage1Map.h"
#include"cTimer.h"
#include"cPlayer.h"
#include"cEnemy.h"

cStage1::cStage1()
{
}

cStage1::~cStage1()
{
}

void cStage1::Init()
{
	m_UI[ui] = IMAGE->FindImage("UI");
	m_timer = new cTimer(0.5);
	map = new cStage1Map;
	

	OBJ->AddObj(new cPlayer());
}

void cStage1::Render()
{
	map->Render();

	//printf("%d\n", OBJ->GetObjectList().size());
}

void cStage1::UIRender()
{

}

void cStage1::Release()
{
	SAFE_DELETE(map);
}

void cStage1::Update()
{
	if (m_timer->Update())
	{
		OBJ->AddObj(new cEnemy(Vec2(rand() % WINSIZEX - WINSIZEX / 2, WINSIZEY / 2)));

	}
	map->Update(100);
}

void cStage1::IUIRender()
{
	RENDER->Render(m_UI[ui], Vec2(0, 0), Vec2(1, 1));
}

