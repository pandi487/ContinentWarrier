#pragma once
#include "cObject.h"
class cPlayerBullet : public cObject
{
private:
	Vec2 m_pos;
	cTexture* m_image;
	float rot;
	FLOAT theta;
public:
	static int Damege;
	cPlayerBullet(Vec2 pos, FLOAT theta);
	virtual ~cPlayerBullet();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

