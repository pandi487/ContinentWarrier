#pragma once
#include "cObject.h"

class cPlayerBullet : public cObject
{
private:
	Vec2 m_pos;
	cTexture* m_image;
	
public:
	int Damege;
	cPlayerBullet(Vec2 pos);
	virtual ~cPlayerBullet();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

