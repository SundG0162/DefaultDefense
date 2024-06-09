#pragma once
#include"Scene.h"
#include"Define.h"
class SceneManager
{
	DECLARE_SINGLETON(SceneManager)
public:
	void setTransition(string sceneName);
	void registerScene(const string& sceneName, Scene* scene);
	void loadScene(const string& sceneName);
public:
	void init();
	void update();
	void render();
public:
	string transitionSceneName;
private:
	Scene* _pActiveScene = nullptr;
	map<string, Scene*> _sceneMap;
};