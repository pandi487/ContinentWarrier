#pragma once
#include"cObject.h"
class cEnemyBullet:public cObject
{
private:
	Vec2 m_pos;
	cTexture* m_image;
	float rot;
	FLOAT theta;
public:
	int Damege;
	cEnemyBullet(Vec2 pos, FLOAT theta);
	virtual ~cEnemyBullet();
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
	BOOL IsMapOut();
};

