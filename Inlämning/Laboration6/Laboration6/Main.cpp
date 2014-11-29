#include "Array.h"


void Test() {

	printf("\nFirst Array\n");
	Array arr1(10);

	arr1.FillArr(0, 10);

	arr1.PrintArr();

	arr1.Sort(0, 10);

	arr1.PrintArr();


	printf("\nSecond Array\n");
	Array arr2(10);

	arr2.FillArr(0, 10);

	arr2.PrintArr();

	arr2.Sort(0, 10);

	arr2.PrintArr();
}


int main() {
	Test();	

	system("pause");
	return 0;
}