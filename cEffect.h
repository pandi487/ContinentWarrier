#pragma once
#include "cObject.h"
class cTimer;
class cEffect : public cObject
{
	cTimer* Frame;
	cTexture* m_image[9];
	Vec2 m_pos;
	int  i = 0;
public:
	cEffect(Vec2 pos);
	virtual ~cEffect();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

