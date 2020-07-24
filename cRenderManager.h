#pragma once
#include "singleton.h"
class cRenderManager : public singleton<cRenderManager>
{
private:
	LPDIRECT3DVERTEXBUFFER9 m_vb;
	LPDIRECT3DINDEXBUFFER9 m_ib;
	IDirect3DPixelShader9 * m_px;
	Vec3 m_CamPos, m_CamUp, m_CamLook;
	D3DLIGHT9 Light;
	struct sVerTexType
	{
		Vec3 m_pos;
		Vec2 m_uv;
		inline static constexpr DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
	};
public:
	cRenderManager();
	~cRenderManager();
	void ResetDevice();
	void Render(cTexture * texturePtr, Vec2 pos ,Vec2 size ,float rot=0,float z= 0);
	void Campos(Vec2 pos);
	void CamShake(float time);
};

#define RENDER cRenderManager::Get()