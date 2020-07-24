#pragma once
#include"cObject.h"

class cTimer;
class cPlayer: public cObject
{
private:
	DWORD m_CurTime, m_OldTime;
	cTexture* m_image;
	Vec2 m_pos;
	cTimer* m_timer;

	BOOL m_bSkillCheck;
	BOOL m_isSkillTimer;;
	cTimer* m_SkillTimer;


public:
	cPlayer();
	virtual ~cPlayer();
	
	int speed = 0;
	int HP;
	// cObject을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

