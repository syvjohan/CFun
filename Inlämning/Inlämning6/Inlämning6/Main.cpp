#include "Array.h"

#include <iostream>
#include <cassert>

using namespace std;

typedef Array<int> arrInt;
typedef Array<double> arrDouble;
typedef Array<short> arrShort;

void Test() {

	Array<int> arrI1, arrI2(3), arrI3(3);
	Array<double> arrD1, arrD2(10.00), arrD3(10.00);
	Array<short> arrS1, arrS2(10), arrS(10);

	arrI3.FillArr(2, 6);
	/*assert(arr1[10] == 7);
	assert(arr1[0] == 1);*/

	arrI2.FillArr(2, 6);
	//assert(arrI1 == arrI2);


}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Test();

	system("PAUSE");
	return 0;
}