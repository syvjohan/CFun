#include "Array.h"

#include <iostream>
#include <cassert>

typedef Array<int> arrInt;

void Test() {
	
	Array<int> arrI1, arrI2(3), arrI3(3), arrI4(7);
	//Array<double> arrD1, arrD2(10.00), arrD3(10.00);
	//Array<short> arrS1, arrS2(10), arrS(10);


	// FillArray
	arrI3.FillArr(2, 26);

	//Checks if the seed is reprodicing a new value.
	arrI2.FillArr(2, 26);
	//Operator ==
	//assert(arrI1 == arrI2);

	arrI4.FillArr(2, 26);

	//Operator !=
	//assert(arrI3 != arrI4);

	//Operator =
	arrI3 = arrI4;

	// Data()
	//assert(arrI3.Data() != arrI4.Data());

	//Reserve
	arrI3.Reserve(15);

	//Capacity
	//assert(arrI3.Capacity() == arrI4.Capacity());

	//ShrinkToFit
	arrI3.ShrinkToFit();
	//assert(arrI3 != arrI4);

	// PushBack
	arrI4.PushBack(5);

	// Length
	//assert(arrI4.Length() == arrI3.Length());

	//Empty
	arrI3.Empty();
	//assert(arrI3.Data() != NULL);
	
	// At.
	arrI3.PushBack(5);
	//assert(arrI3.At(0) != 5);

	////Empty
	//arrI2.Empty();
	//assert(arrI3.Data() != NULL);
	////Empty
	//arrI3.Empty();
	//assert(arrI3.Data() != NULL);
	////Empty
	//arrI4.Empty();
	//assert(arrI3.Data() != NULL);

	//QuickSort
	arrI2.FillArr(0, 10);
	std::cout << arrI2.Data();

	arrI2.Sort(0, 10);
	std::cout << arrI2.Data();

	//Operator =
	arrI3 = 2;
	//Operator []
	//assert(arrI3[0] != 2);

	// Operator +
	arrI3 + 3;
	arrI4 + 45;
	arrI3 + arrI4;
	//assert(arrI3 != 2345);

}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Test();

	system("PAUSE");
	return 0;
}