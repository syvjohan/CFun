#pragma once
#include "Integer.h"
#include "Defs.h"

#include <time.h>
#include <iostream>
#include <cassert>

template<typename T>
class Array;

template<typename T>
bool operator==( Array<T> &arr1, Array<T> &arr2);

template<typename T>
bool operator!=( Array<T> &arr1, Array<T> &arr2);

template<typename T>
std::ostream& operator<<( std::ostream& cout, Array<T> arr);

template<typename T>
class Array {
public:
	Array<T>(int size = NULL); // = NUll. combining a default constructor and a constructor with one argument.
	~Array<T>();

	void QuickSort(T &arr, T left, T right);
	void FillArr(T min, T max);
	T& At(T i);

	T& operator[]( const int index);
	T& At(T i) const;

	friend bool operator==(const Array<T> &arr1, const Array<T> &arr2);
	friend bool operator!=(const Array<T> &arr1, const Array<T> &arr2);

	friend std::ostream& operator<<(std::ostream& cout, const Array<T> arr);

private:
	int size;
	int length;
	Integer *integerArr;
	T Partition(T &arr, T left, T right);
	bool CmpArr(const Array<T> &arr1, const Array<T> &arr2);
	void PrintArr(const Array<T> &arr1);
	T GenerateRandNumbers(T min, T max);
};

//Int rounds off input value to an integer.
template<typename T>
Array<T>::Array(int size) {
	this->size = size;
	length = 0;
	srand((unsigned int)time(NULL)); /*sets the seed in random generator*/

	integerArr = DBG_NEW Integer[size];
}

template<typename T>
Array<T>::~Array() {
	if (integerArr != NULL) {
		delete[] integerArr;
	}
}

//Index operator
template<typename T>
inline T& Array<T>::operator[](const int index) {
	return integerArr[index];
}

template<typename T>
inline T& Array<T>::At(T i) const {
	if (i >= size || i < 0) {
		throw std::out_of_range("Index of array is out of bounds!");
	}
	return integerArr[i];
}

template<typename T>
inline T& Array<T>::At(T i) {
	if (i >= size || i < 0) {
		throw std::out_of_range("Index of array is out of bounds!");
	}
	return integerArr[i];
}


template<typename T>
T Array<T>::GenerateRandNumbers(T min, T max) {
	T value;
	do {
		value = rand() % max + 1;

	} while (value < min);
	return value;
}

template<typename T>
void Array<T>::FillArr(T min, T max) {
	 do {
		T value = GenerateRandNumbers(min, max);
		integerArr[length] = value;
		length++;
	 } while (size != length);
}

template<typename T>
void Array<T>::QuickSort(T &arr, T left, T right) {
	T currValue;
	if (right < left) {
		currValue = Partion(arr, right, left);
		QuickSort(arr, right, currValue); //sort from mid to start.
		QuickSort(arr, currValue + 1, left); //sort from mid to end.
	}
	return;
}

template<typename T>
T Array<T>::Partition(T &arr, T left, T right) {
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

template<typename T>
bool Array<T>::CmpArr(const Array<T> &arr1, const Array<T> &arr2) {
	memcmp(arr1, arr2, sizeof(arr1)) ? true : false;
}

template<typename T>
void PrintArr(const Array<T> &arr1) {
	cout << arr1;
}

template<typename T>
inline bool operator==(const Array<T> &arr1, const Array<T> &arr2) {
	return CmpArr(arr1, arr2);
}

template<typename T>
inline bool operator!=(const Array<T> &arr1, const Array<T> &arr2) {
	return operator!=(arr1, arr2);
}

template<typename T>
std::ostream& operator<<(std::ostream& cout, const Array<T> arr) {
	return PrintArr(arr);
}