#include "Array.h"


void Test() {
	printf("Print size of array: ");
	int input1 = NULL;
	int input2 = NULL;
	scanf("%i", &input1);

	Array arr1(input1);
	input1 = NULL;

	printf("/nPrint min and max value to be filled(Press Enter between values): ");
	scanf(" %i", &input1);
	scanf(" %i", &input2);
	arr1.FillArr(input1, input2);

	printf("/nValues in the array is: ");
	arr1.PrintArr();

	input1 = NULL;
	input2 = NULL;
	printf("/nPrint min and max elements to be sorted(Press Enter between values): ");
	scanf("%i", &input1);
	scanf(" %i", &input2);

	arr1.Sort(input1, input2);

	printf("/nSorted values in array is:");
	arr1.PrintArr();

}


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //Check for memoryLeaks.
	Test();	

	system("pause");
	return 0;
}