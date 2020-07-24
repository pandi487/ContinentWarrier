#include "DXUT.h"
#include "cRenderManager.h"

cRenderManager::cRenderManager()
{

	ZeroMemory(&Light,sizeof(Light));
	g_device->LightEnable(0, true);

	g_device->CreateVertexBuffer(sizeof(sVerTexType)*4 , D3DUSAGE_WRITEONLY, sVerTexType::FVF, D3DPOOL_DEFAULT, &m_vb, NULL);
	sVerTexType * pVerTice = nullptr;

	m_vb->Lock(0, 0, (void**)&pVerTice, 0);

	pVerTice[0].m_pos = Vec3(-0.5, 0.5, 0);
	pVerTice[1].m_pos = Vec3(0.5, 0.5, 0);
	pVerTice[2].m_pos = Vec3(-0.5, -0.5, 0);
	pVerTice[3].m_pos = Vec3(0.5, -0.5, 0);

	pVerTice[0].m_uv = Vec2(0, 0);
	pVerTice[1].m_uv = Vec2(1, 0);
	pVerTice[2].m_uv = Vec2(0, 1);
	pVerTice[3].m_uv = Vec2(1, 1);

	m_vb->Unlock();
	g_device->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_ib, NULL);
	void * pIndice = NULL;
	WORD idx[] = { 1,2,0,1,3,2 };
	m_ib->Lock(0, 0, &pIndice, 0);
	memcpy(pIndice, idx, sizeof(WORD) * 6);
	m_ib->Unlock();

	g_device->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_device->SetFVF(sVerTexType::FVF);
	g_device->SetStreamSource(0, m_vb, 0, sizeof(sVerTexType));
	g_device->SetIndices(m_ib);

	D3DXMATRIXA16 matProj;

	D3DXMatrixOrthoLH(&matProj,WINSIZEX,WINSIZEY,0,100);
	g_device->SetTransform(D3DTS_PROJECTION,&matProj);
	
}

cRenderManager::~cRenderManager()
{
	m_vb->Release();
	m_ib->Release();
}

void cRenderManager::ResetDevice()
{

}

void cRenderManager::Render(cTexture * texturePtr, Vec2 pos, Vec2 size, float rot,float z)
{
	D3DXMATRIXA16 matP, matS, matR, matW;

	D3DXMatrixTranslation(&matP,pos.x,pos.y,z);
	D3DXMatrixScaling(&matS,texturePtr->info.Width*size.x,texturePtr->info.Height *size.y,0);
	D3DXMatrixRotationZ(&matR,rot);
	matW = matS * matR*matP;

	g_device->SetTransform(D3DTS_WORLD,&matW);
	g_device->SetTexture(0,texturePtr->texturePtr);
	g_device->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
}

void cRenderManager::Campos(Vec2 pos)
{
	D3DXMATRIXA16 matCam;
	m_CamLook = Vec3(pos.x, pos.y, 10.f);
	m_CamPos = Vec3(pos.x, pos.y, 100.f);
	m_CamUp = Vec3(0.f, 1.f, 0.f);
	D3DXMatrixLookAtLH(&matCam,&m_CamPos,&m_CamLook,&m_CamUp);
}

void cRenderManager::CamShake(float time)
{
}

