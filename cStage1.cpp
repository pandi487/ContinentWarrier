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
//	m_UI[ui] = IMAGE->FindImage("UI");
	m1_timer = new cTimer(1);

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

int RandomPosition() {
	if (rand() % 2) {
		return 1;
	}
	else {
		return -1;
	}
}

void cStage1::Update()
{
	
	if (m1_timer->Update())
	{
		
		switch (rand() % 3) {
		case 0:
			OBJ->AddObj(new cEnemy(Vec2((RandomPosition() * (rand() % 800)), 580)));
			break;

		case 1:

			OBJ->AddObj(new cEnemy2(Vec2((RandomPosition() * (rand() % 800)), 580)));
			//printf("x값의 범위 : %d\n", (RandomPosition() * (rand() % 800)));
			break;

		case 2:
			OBJ->AddObj(new cEnemy3(Vec2((RandomPosition() * (rand() % 800)), 580)));
			break;
		}
	}
	map->Update(100);
}

void cStage1::IUIRender()
{
//	RENDER->Render(m_UI[ui], Vec2(0, 0), Vec2(1, 1));
}

