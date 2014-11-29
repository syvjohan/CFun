#include "Integer.h"
//#include "Defs.h"

#include <time.h>
#include <iostream>
#include <cassert>
#include <algorithm>



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
	int size;
	int length;
	Integer *integerArr;

	int Partition(Integer *arr, int left, int right);
	void QuickSort(Integer *arr, int left, int right);
	void SetSeed();
	int GenerateRandIntegers(int min, int max);
};


Array::Array(const int size) {
	this->size = size;
	length = 0;
	SetSeed();

	integerArr = new Integer[size];

}

Array::Array() {
	integerArr = NULL;
	length = 0;
	size = 0;
}

Array::~Array() {
	if (integerArr != NULL) {
		delete[] integerArr;
	}
}

void Array::FillArr(int min, int max) {
	 do {
			int value = GenerateRandIntegers(min, max);
			integerArr[length] = value;
			length++;
	 } while (size != length);
}

int Array::GenerateRandIntegers(int min, int max) {
	int value;
	do {
		value = rand() % max + 1;

	} while (value < min);
	return value;
}

void Array::Sort(int begin, int end) {
	QuickSort(integerArr, begin, end);
}

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
	int temp; 

	do {
		do {
			j--;
		} while (x > arr[j].GetValue());
		do {
			i++;
		} while (x < arr[i].GetValue());

		if (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} while (i < j);
	return j;
}

void Array::SetSeed() {
	srand((unsigned int)time(NULL)); /*sets the seed in random generator*/
}

void Array::PrintArr() {
	for (int i = 0; i != length; ++i) {
		std::cout << integerArr[i] << " ";
	}

	printf("\n");
}

inline Integer& Array::operator[](int index) {
	return integerArr[index];
}
