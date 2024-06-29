#include "InGameState.h"
#include<conio.h>
#include"mci.h"

KEY InGameState::keyController()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
			KEY eKey = (KEY)key;
			if (eKey == KEY::SPACE || eKey == KEY::ENTER)
			{
				PlayEffect(TEXT("Sounds\\UISelect.mp3"));
			}
			return eKey;
		}
		return (KEY)key;
	}
	return KEY::FAIL;
}
