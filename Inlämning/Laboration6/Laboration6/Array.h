#include "Integer.h"
#include "Defs.h"

#include <time.h>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>


class Array {
public:
	Array(const int size);
	Array();

	~Array();
	
	Integer& Array::operator[](int index);

	void FillArr(int min, int max);
	void Sort(int begin, int end);
	void PrintArr();

private:
	//The private function/variables cannot be reached outside the class.
	int size;
	int length;
	Integer *integerArr;

	int Partition(Integer *arr, int left, int right);
	void QuickSort(Integer *arr, int left, int right);
	int GenerateRandIntegers(int min, int max);
};


Array::Array(const int size) {
	this->size = size; //set class private variable size to input size from user.
	length = 0;

	integerArr = DBG_NEW Integer[size];

}

Array::Array() {
	integerArr = NULL;
	length = 0;
	size = 0;
}

//Kills the integerArr objects.
Array::~Array() {
	if (integerArr != NULL) {
		delete[] integerArr;
	}
}

void Array::FillArr(int min, int max) {
	 do {
			int value = GenerateRandIntegers(min, max);
			integerArr[length] = value; //Fill the array.
			length++;
	 } while (size != length);
}

int Array::GenerateRandIntegers(int min, int max) {
	int value;
	do {
		//The random class generates "random" values for ous. The random class uses time for creating new values.
		value = rand() % max + 1;

	} while (value < min);
	return value;
}

//Public interface for the QuickSort alghorithm.
void Array::Sort(int begin, int end) {
	QuickSort(integerArr, begin, end);
}

//Function is recursive sort the array in 2 steps.
//Arguments begin and end makes it possible to decide how many elements that should be sorted. Decide start and end point.
void Array::QuickSort(Integer *arr, int begin, int end) {
	int middle; 
	if (begin < end) {
		middle = Partition(arr, begin, end);
		QuickSort(arr, begin, middle); //sort from mid to start.
		QuickSort(arr, middle + 1, end); //sort from mid to end.
	}
}

int Array::Partition(Integer *arr, int begin, int end) {
	int x = arr[begin]; 
	int i = begin - 1;
	int j = end + 1;
	int temp; //holds an value when i and j is changing value.

	do {
		do {
			j--;
		} while (x > arr[j].GetValue()); //GetValues returns the value in Integer. Cannot compare Integer values with int.
		do {
			i++;
		} while (x < arr[i].GetValue());//GetValues returns the value in Integer Cannot compare Integer values with int.

		if (i < j) {
			//Swaps the values.
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} while (i < j);
	return j;
}

void Array::PrintArr() {
	for (int i = 0; i != length; ++i) {
		std::cout << integerArr[i] << " ";
	}

	printf("\n");
}

//Operator needed for indexing integerArr[].
inline Integer& Array::operator[](int index) {
	return integerArr[index];
}
