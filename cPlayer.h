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
	cTimer* z_timer;
	BOOL m_bIsSkillOn;		// ��ų ���� ����
	BOOL m_bIsSkillKeyOn;		// ��ų Ű �Է� ���� ����
	cTimer* m_SkillTimer;		// ��ų Ÿ�̸� (��ų ���ӽð�)
	float field = 1.0f;
	float y = -370.0f;
	cTimer* s_timer;
	BOOL IsShow;

	cTimer* h_timer;
	cTimer* h_SkillTimer;
	BOOL h_bIsSkillOn;
	BOOL h_bIsSkillKeyOn;
	float h_field = 1.0f;
	float Y = -370.0f;
	BOOL h_IsShow;
	cTimer* hs_timer;

public:
	cPlayer();
	virtual ~cPlayer();
	int speed = 0;
	static int HP;
	// cObject��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(cObject* obj) override;
};

