#include "Core.h"
#include "Define.h"
#include"SceneManager.h"
#include "TitleScene.h"
#include "InGameScene.h"
#include"TransitionScene.h"
#include"InfoScene.h"

Core::Core()
{
}
Core::~Core()
{
}
void Core::init()
{
	GET_SINGLETON(SceneManager)->init();

	GET_SINGLETON(SceneManager)->registerScene("TitleScene", new TitleScene);
	GET_SINGLETON(SceneManager)->registerScene("InGameScene", new InGameScene);
	GET_SINGLETON(SceneManager)->registerScene("TransitionScene", new TransitionScene);
	GET_SINGLETON(SceneManager)->registerScene("InfoScene", new InfoScene);

	GET_SINGLETON(SceneManager)->loadScene("TitleScene");
}
void Core::update()
{
	GET_SINGLETON(SceneManager)->update();
}
void Core::render()
{
	GET_SINGLETON(SceneManager)->render();
}