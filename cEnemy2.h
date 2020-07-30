#pragma once
#include "cObject.h"
class cTimer;
class cEnemy2 : public cObject
{
private:
	cTexture* m_image;
	Vec2 m_pos;
	Vec2 pos;
	float a = 0;
	float rot;
	cTimer* m_timer;
public:
	int HP;
	static int Damege;
	cEnemy2(Vec2 pos);
	virtual ~cEnemy2();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj)override;
};

