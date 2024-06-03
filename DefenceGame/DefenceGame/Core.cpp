#include "Core.h"
#include "Define.h"
#include"SceneManager.h"
#include "TitleScene.h"
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