#pragma once
#include "Integer.h"
#include "Defs.h"

template<typename T>
class Array {
public:
	Array<T>(int size = NULL); // = NUll. combining a default constructor and a constructor with one argument.
	~Array();

	int GenerateRandNumbers(int min, int max);
	void QuickSort(T &arr, T left, T right);

	Array<T>& operator[](int index);

private:
	int size;
	Integer *integer;
	T Partion(T &arr, T left, T right);
};

template<typename T>
Array<T>::Array(int size) {
	this->size = size;
	srand(time(NULL)); /*sets the seed in random generator*/

	integer = DBG_NEW Integer[size];
}

template<typename T>
Array<T>::~Array() {
	if (!Integer) {
		delete[] integer;
	}
}

//Index operator
template<typename T>
inline Array<T>& Array<T>::operator[](int index) {
	return integer[index];
}


template<typename T>
int Array<T>::GenerateRandNumbers(int min, int max) {
	int value;
	do {
		value = rand() % max + 1;

	} while (value < min);

}

template<typename T>
void Array<T>::QuickSort(T &arr, T left, T right) {
	T currValue;
	if (right < left) {
		currValue = Partion(arr, right, left);
		QuickSort(arr, right, currValue); //sort the first section.
		QuickSort(arr, currValue + 1, left); //sort second section.
	}
	return;
}

template<typename T>
T Array<T>::Partion(T &arr, T left, T right) {
	T x = arr[right];
	T i = right - 1;
	T j = left + 1;
	T temp;
	do {
		do {
			j--;
		} while (x > arr[j]);
		do {
			i++;
		} while (x < arr[i]);

		if (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} while (i < j);
	return j;
}