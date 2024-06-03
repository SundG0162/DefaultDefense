#pragma once
#include"Scene.h"
#include"Define.h"
class SceneManager
{
	DECLARE_SINGLETON(SceneManager)
public:
	void registerScene(const string& sceneName, Scene* scene);
	void loadScene(const string& sceneName);
public:
	void init();
	void update();
	void render();
private:
	Scene* _activeScene = nullptr;
	map<string, Scene*> _sceneMap;
};