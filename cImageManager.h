#pragma once
#include "singleton.h"
class cTexture
{
private:
public:
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texturePtr;
	cTexture() {};
	cTexture(const char * sz)
	{
		D3DXCreateTextureFromFileExA(g_device, sz, -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr);
	}
	virtual ~cTexture() {};

	
};
class cMultiTexture;
class cImageManager :public singleton<cImageManager>
{
private:
	LPD3DXFONT pFont ;
	map <string, cMultiTexture*>m_image;
	LPD3DXSPRITE m_sprite= nullptr;
public:
	void Begin();
	void End();
	void ResetDevice();
	void LostDevice();
	cImageManager();
	~cImageManager();
	void AddImage(const string  & key,const string  & path,int cnt = 1 );
	cTexture * FindImage(const string  & key,int cnt = 0);
	cMultiTexture* FindMultiTexture(const string & key);
	void TextDraw(string str,Vec2 pos , float size,bool Center ,D3DCOLOR color);
	void Render(cTexture * texturePtr, Vec2 pos, Vec2 size = Vec2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255,255,255));
	void CenterRender(cTexture * texturePtr, Vec2 pos, Vec2 size = Vec2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
};

#define IMAGE cImageManager::Get()
