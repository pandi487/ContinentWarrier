#include "DXUT.h"
#include "cSceneManager.h"

cSceneManager::cSceneManager()
{
}

cSceneManager::~cSceneManager()
{
	Release();
}

cScene * cSceneManager::AddScene(const string key, cScene * _newscene)
{
	if (!_newscene)
		return nullptr;
	if (m_scene.find(key) != m_scene.end())
		return nullptr;
	m_scene[key] = _newscene;
	return _newscene;
}

void cSceneManager::ChangeScene(const string key)
{
	auto find = m_scene.find(key);
	if (find == m_scene.end())
	{
		return;
	}
	m_NextScene = find->second;
	
}

void cSceneManager::Render()
{
	if (m_NowScene)
	{
		m_NowScene->Render();
	}
}

void cSceneManager::Update()
{

	if (m_NextScene)
	{
		if (m_NowScene)
		{
			m_NowScene->Release();
		}
		OBJ->Release();
		
		m_NowScene = m_NextScene;
		m_NextScene =nullptr;
		m_NowScene->Init();
	}
	if (m_NowScene)
	{
		m_NowScene->Update();
	}
}

void cSceneManager::IUIRender()
{
	if (m_NowScene)
	{
		m_NowScene->IUIRender();
	}
}

void cSceneManager::UIRender()
{
	if (m_NowScene)
	{
		m_NowScene->UIRender();
	}
}

void cSceneManager::Release()
{
	OBJ->Release();
	if (m_NowScene)
	{
		m_NowScene->Release();
	}
	for (auto iter : m_scene)
	{
		SAFE_DELETE(iter.second );
	}
	m_scene.clear();
}
