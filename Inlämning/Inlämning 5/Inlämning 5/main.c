#include "defs.h"
#include "menu.h"

int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Check for memoryLeaks.
	drawMenu();

	return 0;
}