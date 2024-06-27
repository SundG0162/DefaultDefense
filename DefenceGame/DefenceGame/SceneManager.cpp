#include<string>
#include "SceneManager.h"
#include"Define.h"
SceneManager* SceneManager::m_pInst = nullptr;

void SceneManager::registerScene(const string& sceneName, Scene* scene)
{
	_sceneMap.insert({ sceneName, scene });
}
void SceneManager::loadScene(const string& sceneName)
{
	system("cls");
	auto iter = _sceneMap.find(sceneName);
	if (iter != _sceneMap.end())
	{
		_pActiveScene = iter->second;
		_pActiveScene->init();
	}
}

void SceneManager::init()
{
	_pActiveScene = nullptr;
}
void SceneManager::update()
{
	_pActiveScene->update();
}

void SceneManager::render()
{
	_pActiveScene->render();
}
