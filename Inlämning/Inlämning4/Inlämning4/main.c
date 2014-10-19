//Johan Fredriksson AB5785.
#include "menu.h"
#include "defs.h"

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Check for memoryLeaks.
	draw_menu();

	return 0;
}