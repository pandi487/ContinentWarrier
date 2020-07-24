#pragma once
#include"cScene.h"
class cStage1Map;
class cTimer;
class cStage1:public cScene
{
private:
	enum UI
	{
		ui,
	};
	cTexture* m_UI[10];
	cTimer* m_timer;
	cStage1Map* map;
	cPlayer* m_Player;
public:
	cStage1();
	~cStage1();
	virtual void Init();
	virtual void Render();
	virtual void UIRender();
	virtual void Release();
	virtual void Update();
	virtual void IUIRender();
};

