// Johan Fredriksson AB5785.
#include "Defs.h"
#include "GameManager.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Check for memoryLeaks.
	
	//GameManager
	initializeGame();

	return 0;
}
//exit(0) tv�ngsst�nger programmet utan att frig�ra minnet innana avslut, st�nger med felkod 0. D�lig programmeringsstil!!!!
