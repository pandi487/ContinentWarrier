#include "DXUT.h"
#include "cStage1.h"
#include "cStage1Map.h"
#include "cTimer.h"
#include "cPlayer.h"
#include "cEnemy.h"
#include "cEnemy2.h"
#include "cEnemy3.h"
#include <time.h>

cStage1::cStage1()
{
}

cStage1::~cStage1()
{
}

void cStage1::Init()
{
	m_UI[ui] = IMAGE->FindImage("UI");
	m_timer = new cTimer(5);
	map = new cStage1Map;
	
	srand((unsigned int)time(NULL));
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
		switch (rand() % 3) {
		case 0:
			OBJ->AddObj(new cEnemy(Vec2((((rand() % 2) ? 1 : -1) * 500), WINSIZEY / 2)));
			break;
		case 1:
			OBJ->AddObj(new cEnemy2(Vec2((((rand() % 2) ? 1 : -1) * 500), WINSIZEY / 2)));
			break;
		case 2:
			OBJ->AddObj(new cEnemy3(Vec2((((rand() % 2) ? 1 : -1) * 450), WINSIZEY / 2)));
			break;
		}
	}
	map->Update(100);
}

void cStage1::IUIRender()
{
	RENDER->Render(m_UI[ui], Vec2(0, 0), Vec2(1, 1));
}

