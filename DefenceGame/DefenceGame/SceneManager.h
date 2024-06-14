#pragma once
#include"Scene.h"
#include"Define.h"
class SceneManager
{
	DECLARE_SINGLETON(SceneManager)
public:
	void registerScene(const string& sceneName, Scene* scene);
	void loadScene(const string& sceneName);
	void setTransition(string sceneName) { _transitionSceneName = sceneName; }
	string getTransitionScene() { return _transitionSceneName; }
public:
	void init();
	void update();
	void render();
private:
	Scene* _pActiveScene = nullptr;
	map<string, Scene*> _sceneMap;
	string _transitionSceneName;
};