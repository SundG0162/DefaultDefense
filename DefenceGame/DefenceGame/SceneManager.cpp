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
	auto iter = _sceneMap.find(sceneName);
	if (iter != _sceneMap.end())
	{
		_activeScene = iter->second;
		_activeScene->init();
	}
}
void SceneManager::init()
{
	_activeScene = nullptr;
}
void SceneManager::update()
{
	_activeScene->update();
}

void SceneManager::render()
{
	_activeScene->render();
}
