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

	BOOL m_bIsSkillOn;		// ��ų ���� ����
	BOOL m_bIsSkillKeyOn;		// ��ų Ű �Է� ���� ����
	cTimer* m_SkillTimer;		// ��ų Ÿ�̸� (��ų ���ӽð�)


public:
	cPlayer();
	virtual ~cPlayer();
	
	int speed = 0;
	int HP;
	// cObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

