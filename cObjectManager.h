#pragma once
#include "singleton.h"
class cObject;
class cPlayer;
class cObjectManager : public singleton<cObjectManager>
{
private:
	list<cObject *>m_objlist;
public:
	cObjectManager();
	~cObjectManager();
public:
	cObject * AddObj(cObject * _newObj);
	void Collision(cObject  * obj );
	void ObbColl(cObject * obj);
	void Update();
	void Render();
	void Release();
	void UIRender();
	RECT rt;
	cPlayer * m_player = nullptr;

	inline list<cObject*> GetObjectList() {
		return m_objlist;
	}
	Vec2 GetWidthVector(RECT obj ,FLOAT rot);
	Vec2 GetHeightVector(RECT obj, FLOAT rot);
};

#define OBJ cObjectManager::Get()