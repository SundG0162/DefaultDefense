#include "Core.h"
#include "Define.h"
#include"SceneManager.h"
#include "TitleScene.h"
#include "InGameScene.h"
#include"TransitionScene.h"
#include"InfoScene.h"
#include"EntityManager.h"

Core::Core()
{
}
Core::~Core()
{
}
void Core::init()
{
	//콘솔 드래그, 클릭 막는코드
	DWORD consoleModePrev;
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);    
	GetConsoleMode(handle, &consoleModePrev);    
	SetConsoleMode(handle, consoleModePrev & ~ENABLE_QUICK_EDIT_MODE);

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