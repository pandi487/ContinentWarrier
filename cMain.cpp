#include "DXUT.h"
#include "cMain.h"
#include "cTitleScene.h"
#include"cStage1.h"

cMain::cMain()
{
}

cMain::~cMain()
{
}

void cMain::Update()
{
	KEY->Update();
	OBJ->Update();
	SCENE->Update();
}

void cMain::Init()
{
	IMAGE->AddImage("Map","./image/Stage1/map.png");
	RENDER->Campos(Vec2(0, 0));
	SCENE->AddScene("Title", new cTitleScene);

	IMAGE->AddImage("Player", "./image/Player.png");
	SCENE->AddScene("Stage1", new cStage1);
	IMAGE->AddImage("Title", "./image/Title/Title.png");

	IMAGE->AddImage("PlayOn","./image/Title/PlayOn.png");
	IMAGE->AddImage("PlayOff", "./image/Title/PlayOff.png");

	IMAGE->AddImage("HowOn", "./image/Title/HowOn.png");
	IMAGE->AddImage("HowOff", "./image/Title/HowOff.png");

	IMAGE->AddImage("CreditOn", "./image/Title/CreditOn.png");
	IMAGE->AddImage("CreditOff", "./image/Title/CreditOff.png");

	//IMAGE->AddImage("OptionOn","./image/Title/OptionOn.png");
	//IMAGE->AddImage("OptionOff", "./image/Title/OptionOff.png");

	IMAGE->AddImage("ExitOn","./image/Title/ExitOn.png");
	IMAGE->AddImage("ExitOff", "./image/Title/ExitOff.png");

	IMAGE->AddImage("Credit", "./image/Title/Credit/Credit.png");
	IMAGE->AddImage("Button", "./image/Title/Credit/Button.png");
	IMAGE->AddImage("HowTo", "./image/Title/Credit/How.png");
	IMAGE->AddImage("Mouse", "./image/Mouse.png");
	IMAGE->AddImage("PlayerBullet", "./image/PlayerBullet.png");

	IMAGE->AddImage("Enemy", "./image/Stage1/Enemy.png");
	IMAGE->AddImage("Enemy2", "./image/Stage1/Enemy2.png");
	IMAGE->AddImage("Enemy3", "./image/Stage1/Enemy3.png");
	IMAGE->AddImage("UI", "./image/Stage1/UI.png");

	SCENE->ChangeScene("Title");
	
	IMAGE->AddImage("EnemyBullet", "./image/EnemyBullet.png");

	IMAGE->AddImage("Effect1", "./image/Effect/Effect1.png");
	IMAGE->AddImage("Effect2", "./image/Effect/Effect2.png");
	IMAGE->AddImage("Effect3", "./image/Effect/Effect3.png");
	IMAGE->AddImage("Effect4", "./image/Effect/Effect4.png");
	IMAGE->AddImage("Effect5", "./image/Effect/Effect5.png");
	IMAGE->AddImage("Effect6", "./image/Effect/Effect6.png");
	IMAGE->AddImage("Effect7", "./image/Effect/Effect7.png");
	IMAGE->AddImage("Effect8", "./image/Effect/Effect8.png");
	IMAGE->AddImage("Effect9", "./image/Effect/Effect9.png");

	IMAGE->AddImage("SkillOff", "./image/UI/skillColl.png");
	IMAGE->AddImage("SkillOn", "./image/UI/skillUI.png");

	IMAGE->AddImage("SkillOff2", "./image/UI/skillColl2.png");
	IMAGE->AddImage("HP", "./image/UI/HP.png");
	IMAGE->AddImage("HPbarOn", "./image/HPbarOn.png");
	IMAGE->AddImage("HPbarOff", "./image/HPbarOff.png");
	IMAGE->AddImage("GameClear", "./image/GameClear.png");

	IMAGE->AddImage("GameOver", "./image/GameOver.png");

}

void cMain::Render()
{
	SCENE->Render();
	OBJ->Render();
	SCENE->IUIRender();

	IMAGE->Begin();

	OBJ->UIRender();
	SCENE->UIRender();

	IMAGE->End();
}

void cMain::Release()
{
	cRenderManager::ReleaseInstance();
	cImageManager::ReleaseInstance();
	cKeyManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
	cObjectManager::ReleaseInstance();

}

void cMain::ResetDevice()
{
	IMAGE->ResetDevice();
}

void cMain::LostDevice()
{
	IMAGE->LostDevice();
}
