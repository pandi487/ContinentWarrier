#include "DXUT.h"
#include "cImageManager.h"
#include "cMultiTexture.h"
void cImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void cImageManager::End()
{
	m_sprite->End();
}

void cImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}

void cImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

cImageManager::cImageManager()
{
	D3DXCreateSprite(g_device,&m_sprite);
}

cImageManager::~cImageManager()
{
	for (auto iter : m_image)
	{
		SAFE_DELETE(iter.second);
	}
	m_sprite->Release();
}

void cImageManager::AddImage(const string & key, const string & path,int cnt)
{
	auto find = m_image.find(key);
	if (find != m_image.end())
	{
		return;
	}
	else if (cnt < 0)
	{
		return;
	}
	cMultiTexture* text = new cMultiTexture;
	text->AddImage(path,cnt);
	m_image[key] = text;

}

cTexture* cImageManager::FindImage(const string& key, int cnt)
{
	auto find = m_image.find(key);
	if (find == m_image.end())
	{
		return nullptr;
	}
	return find->second->FindImage(cnt);
}

cMultiTexture* cImageManager::FindMultiTexture(const string& key)
{
	auto find = m_image.find(key);
	if (find == m_image.end())
	{
		return nullptr;
	}
	return find->second;
}

void cImageManager::TextDraw(string str, Vec2 pos, float size,bool center, D3DCOLOR color)
{
		D3DXMATRIXA16 mat;
		if (!center)
		{
			D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &pFont);
			D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
		}
		else
		{
			D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Black Ops One", &pFont);
			D3DXMatrixTranslation(&mat, pos.x - size * (str.size()*0.25), pos.y - size / 2.f, 0);
		}
		m_sprite->SetTransform(&mat);
		pFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
		SAFE_RELEASE(pFont);

}

void cImageManager::Render(cTexture * texturePtr, Vec2 pos, Vec2 size, float rot,D3DCOLOR color)
{

	D3DXMATRIXA16 mat;
	if (!texturePtr)
	{
		return;
	}
	else
	{

		D3DXMatrixTransformation2D(&mat,nullptr,0,&size,nullptr,rot,&pos);
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr,nullptr,nullptr,nullptr,color);
	}
	  
}

void cImageManager::CenterRender(cTexture * texturePtr, Vec2 pos, Vec2 size, float rot, D3DCOLOR color)
{
	Render(texturePtr,Vec2(pos.x-texturePtr->info.Width/2,pos.y-texturePtr->info.Height/2),size,rot,color);
}
