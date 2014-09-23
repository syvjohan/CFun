#include "Random.h"

int generateRndNum(int maxSize) {
	srand(time(NULL)); /*sets the seed in random generator*/
	return rand() % maxSize + 1;
}
