#include "DXUT.h"
#include "cKeyManager.h"

cKeyManager::cKeyManager()
{
	ZeroMemory(CurKey,sizeof(256));
	ZeroMemory(OldKey, sizeof(256));


}

cKeyManager::~cKeyManager()
{
}

void cKeyManager::Update()
{
	GetCursorPos(&pt);
	ClientToScreen(DXUTGetHWND(), &pt);
	memcpy(OldKey,CurKey,256);
	for (int i = 0; i < 256; i++)
	{
		CurKey[i] = GetAsyncKeyState(i)& 0x8000;
	}
}

bool cKeyManager::KeyStay(int key)
{
	return CurKey[key];
}

bool cKeyManager::KeyUp(int key)
{
	return !CurKey[key] && OldKey[key];
}

bool cKeyManager::KeyPress(int key)
{
	return CurKey[key]&&!OldKey[key];
}
