#pragma once
#include "cScene.h"
class cScene;
class cSceneManager : public singleton<cSceneManager>
{
private:
	cScene * m_NowScene = nullptr;
	cScene * m_NextScene = nullptr;
public:
	map<string, cScene*>m_scene;
	cSceneManager();
	~cSceneManager();
public:
	cScene * AddScene(const string key, cScene * _newscene);
	void ChangeScene(const string key);
	void Render();
	void Update();
	void IUIRender();

	void UIRender();
	void Release();
};

#define SCENE cSceneManager::Get()