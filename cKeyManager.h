#pragma once
#include "singleton.h"
class cKeyManager : public singleton<cKeyManager>
{
private:
	int CurKey[256];
	int OldKey[256];
public:
	cKeyManager();
	~cKeyManager();
public:
	void Update();
	bool KeyStay(int key);
	bool KeyUp(int key);
	bool KeyPress(int key);
	POINT pt;
	HWND hwnd;
	Vec2 GetCurPos() { return Vec2(pt.x-WINSIZEX/2-40,pt.y-WINSIZEY/2-75); }
	//Vec2 GetCurPos() { return Vec2(pt.x - WINSIZEX / 2 , pt.y - WINSIZEY / 2 ); }

};

#define KEY cKeyManager::Get()