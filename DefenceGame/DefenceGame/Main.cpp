#include"Core.h"

int main()
{
	Core core = Core();

	core.init();
	while (true)
	{
		core.update();
		core.render();
	}
}