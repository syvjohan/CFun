#include "Array.h"

#include <iostream>
#include <cassert>

using namespace std;

void Test() {
	Array<int> arr1(10), arr2(10);

	/*arr1.GenerateRandNumbers(2, 6);
	assert(arr1[10] == 7);
	assert(arr1[0] == 1);

	arr2.GenerateRandNumbers(2, 6);
	assert(arr1 == arr2);
*/

}

int Main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Test();

	system("PAUSE");
	return 0;
}