#include "InGameState.h"
#include<conio.h>

KEY InGameState::keyController()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
			return (KEY)key;
		}
		return (KEY)key;
	}
	return KEY::FAIL;
}
