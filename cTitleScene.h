#pragma once
#include "cScene.h"
class cTimer;
class cTitleScene  : public cScene
{
private:
	HWND hwnd;
	cTimer * m_Timer;
	int Num = 0;
	cTexture * m_mouse;
	RECT _1, _2, _3, _4, _5,_6;
	enum Title
	{
		PlayOn,
		PlayOff,
		OptionOn,
		OptionOff,
		ExitOn,
		ExitOff,
		HowOn,
		HowOff,
		CreditOff,
		CreditOn,
		BG,
		How,
		Credit,
		Button
	};
	cTexture* m_Title[15];
	POINT m_Pos;
	bool HowToOn ,m_CreditOn;
public:

	cTitleScene();
	virtual ~cTitleScene();
	virtual void Init() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
	virtual void IUIRender() override;

	virtual void Update() override;
};

