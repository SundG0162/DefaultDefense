#include "Core.h"
#include "Define.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "InGameScene.h"
#include "TransitionScene.h"
#include "InfoScene.h"
#include "EntityManager.h"
#include "EndScene.h"
#include "BadAppleScene.h"

Core::Core()
{
}
Core::~Core()
{
}
void Core::init()
{
	lockDragAndClick();
	lockConsoleScroll();

	GET_SINGLETON(EntityManager)->init();
	GET_SINGLETON(WaveManager)->init();
	GET_SINGLETON(SceneManager)->init();
	GET_SINGLETON(SceneManager)->registerScene("TitleScene", new TitleScene);
	GET_SINGLETON(SceneManager)->registerScene("InGameScene", new InGameScene);
	GET_SINGLETON(SceneManager)->registerScene("TransitionScene", new TransitionScene);
	GET_SINGLETON(SceneManager)->registerScene("InfoScene", new InfoScene);
	GET_SINGLETON(SceneManager)->registerScene("EndScene", new EndScene);
	GET_SINGLETON(SceneManager)->registerScene("BadAppleScene", new BadAppleScene);

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