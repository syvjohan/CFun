#pragma once
#include "Integer.h"
#include "Defs.h"

#include <time.h>
#include <iostream>
#include <cassert>
#include <algorithm>

//Forward declaration off the class
template<typename T>
class Array;

template<typename T>
bool operator==( Array<T> &arr1, Array<T> &arr2);

template<typename T>
bool operator!=( Array<T> &arr1, Array<T> &arr2);

template<typename T>
bool operator==( Integer &arr1, T &number);
	
template<typename T>
bool operator!=( Integer &arr1, T &number);

template<typename T>
std::ostream& operator<<( std::ostream& cout, Array<T> arr);

template<typename T>
class Array {
public:
	Array<T>(const int size);
	Array<T>();
	Array<T>(const T* data);
	Array<T>(const Array<T> &rhs);
	//No constructor for adding one single Integer se PushBack function and operators instead...
	
	~Array<T>();

	void Sort(T begin, T end);
	void FillArr(T min, T max);
	
	Integer& operator[]( T index);

	Array<T>& operator=(const Array<T>& rhs);
	Array<T>& operator=(const T* number);
	Array<T>& operator=(T number);

	Array<T>& operator+=(const Array<T>& rhs);
	Array<T>& operator+=(T* number);

	Array<T> operator+(const Array<T>& rhs);
	Array<T> operator+(const T* number);

	Integer& At(const int i);
	Integer& At(const int i) const;
	void ShrinkToFit();
	int Length() const;
	const Integer *Data() const;
	int Capacity() const;
	void PushBack(const T number);
	void Reserve(const int newSize);
	void Empty();

	friend bool operator==(const Integer &arr1, const T &number);
	friend bool operator==(const Array<T> &arr1, const Array<T> &arr2);

	friend bool operator!=(const Array<T> &arr1, const Array<T> &arr2);
	friend bool operator!=(const Integer &arr1, const T &number);

	friend std::ostream& operator<<(std::ostream& cout, const Array<T> arr);

private:
	int size;
	int length;
	Integer *integerArr;

	void QuickSort(Integer *arr, T left, T right);
	T Partition(Integer *arr, T left, T right);
	bool CmpArrVSArr(const Array<T> &arr1, const Array<T> &arr2);
	bool CmpArrVST(const Integer &arr1, const T &number);
	T GenerateRandIntegers(T min, T max);
	void SetSeed();
	int ArrLength(const T *Integers) const;
	void Concat(const Array<T> &r);
};

//Default constructor.
template<typename T>
Array<T>::Array() {
	integerArr = NULL;
	size = 0;
	length = 0;
	SetSeed();
}

//Int rounds off input value to an Integer. Works as std::basic_string Reserve function.
template<typename T>
Array<T>::Array(const int size) {
	integerArr = NULL;
	this->size = size;
	length = 0;
	SetSeed();

	integerArr = DBG_NEW Integer[size];
	
}

template<typename T>
Array<T>::Array(const T* data) {
	length = ArrLength(data);
	size = length;
	integerArr = DBG_NEW Integer[size];

	SetSeed();

	memcpy(integerArr, data, length);
}
 
//Copy constructor.
template<typename T>
Array<T>::Array(const Array<T> &rhs) {
	integerArr = NULL;
	size = 0;
	length = 0;
	SetSeed();
	Concat(rhs);
}

template<typename T>
Array<T>::~Array() {
	if (integerArr != NULL) {
		delete[] integerArr;
	}
}

template<typename T>
void Array<T>::SetSeed() {
	srand((unsigned int)time(NULL)); /*sets the seed in random generator*/
}

//Index operator
template<typename T>
inline Integer& Array<T>::operator[](T index) {
	return integerArr[index];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
	if (rhs.integerArr == integerArr) {
		return *this;
	}
	
	delete[] integerArr;
	integerArr = NULL;
	length = 0;
	size = 0;
	Concat(rhs);

	return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(const T* numbers) {
	return (*this = Array<T>(numbers));
}

template<typename T>
Array<T>& Array<T>::operator=(T number) {
	if (size <= 1) {
		Concat(number);
	}

	integerArr[0] = number;

	return *this;
}

template<typename T>
Array<T>& Array<T>::operator+=(const Array<T>& rhs) {
	Concat(rhs);
	return *this;
}

template<typename T>
Array<T>& Array<T>::operator+=(T* numbers) {
	Concat(numbers);
	return *this;
}

template<typename T>
Array<T> Array<T>::operator+(const Array<T>& rhs) {
	Array<T> a = *this;
	a.Concat(rhs);
	return a;
}

template<typename T>
Array<T> Array<T>::operator+(const T* numbers) {
	Array<T> a = *this;
	a.Concat(numbers);
	return a;
}


template<typename T>
inline Integer& Array<T>::At(const int i) const {
	if (i >= size || i < 0) {
		throw std::out_of_range("Index of array is out of bounds!");
	}
	return integerArr[i];
}

template<typename T>
inline Integer& Array<T>::At(const int i) {
	if (i >= size || i < 0) {
		throw std::out_of_range("Index of array is out of bounds!");
	}
	return integerArr[i];
}

template<typename T>
int Array<T>::Length() const {
	return length;
}

template<typename T>
const Integer* Array<T>::Data() const {
	return integerArr;
}

template<typename T>
int Array<T>::Capacity() const {
	return size;
}

template<typename T>
void Array<T>::ShrinkToFit() {
	if (size > length) {
		size = length;
		Integer *temp = integerArr;
		integerArr = DBG_NEW Integer[length];
		memcpy(integerArr, temp, length);
		delete[] temp;
	}
}

template<typename T>
void Array<T>::Reserve(const int newSize) {
	if (newSize <= size) {
		return;
	}

	size = newSize;
	T *temp = DBG_NEW T[size];
	memcpy(integerArr, temp, size);
	delete[] temp;
}

template<typename T>
void Array<T>::Concat(const Array<T> &r) {
	int newLength = length + r.length;

	if (integerArr == NULL) {
		integerArr = DBG_NEW Integer[size];

	} else if (newLength > size) {
		int newSize = std::max(newLength, size * 2);

		Integer *temp = integerArr;
		integerArr = DBG_NEW Integer[size];
		size = newSize;
		memcpy(integerArr, temp, length);
		delete[] temp;
	}

	memcpy(integerArr + length, r.integerArr, r.length);
	length = newLength;
}

template<typename T>
void Array<T>::PushBack(const T Integer) {
	Concat(&Integer);
}

//It is more efficient to set the array length, capacity to zero and the first element to NULL instead of emptying the array.
//Nothing will be achived with emptying the values in the array, thats not how array works...
//The values that is left will be overwriten on next fill. This is the same technique as std::basic_string uses.
template<typename T>
void Array<T>::Empty() {
	integerArr[0] = NULL;
	size = 0;
	length = 0;
}

template<typename T>
T Array<T>::GenerateRandIntegers(T min, T max) {
	T value;
	do {
		value = rand() % max + 1;

	} while (value < min);
	return value;
}


template<typename T>
void Array<T>::FillArr(T min, T max) {
	 do {
			T value = GenerateRandIntegers(min, max);
			integerArr[length] = value;
			length++;
	 } while (size != length);
}

//QuickSort interface.
template<typename T>
void Array<T>::Sort(T begin, T end) {
	QuickSort(integerArr, begin, end);
}

template<typename T>
void Array<T>::QuickSort(Integer *arr, T left, T right) {
	T currValue; 
	if (right < left) {
		currValue = Partition(arr, right, left);
		QuickSort(arr, right, currValue); //sort from mid to start.
		QuickSort(arr, currValue + 1, left); //sort from mid to end.
	}
}

template<typename T>
T Array<T>::Partition(Integer *arr, T left, T right) {  
	Integer x = arr[right].GetValue(); 
	T i = right; //- 1
	T j = left; // + 1
	T temp; 

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

//Counts the elements and return the length. change NULL to '/0' and you have  c version of strlen
template<typename T>
int Array<T>::ArrLength(const T *Integers) const {
	size_t len = 0;
	while (*Integers != NULL) {
		*Integers++;
		len++;
	}

	return len;
}

template<typename T>
bool Array<T>::CmpArrVSArr(const Array<T> &arr1, const Array<T> &arr2) {
	memcmp(arr1, arr2, sizeof(arr1)) ? true : false;
}

template<typename T>
bool Array<T>::CmpArrVST(const Integer &arr1, const T &number) {
	return arr1.GetValue() == number;
}

template<typename T>
inline bool operator==(const Array<T> &arr1, const Array<T> &arr2) {
	return CmpArrVSArr(arr1, arr2);
}

template<typename T>
inline bool operator!=(const Array<T> &arr1, const Array<T> &arr2) {
	return !CmpArrVSArr(arr1, arr2);
}

template<typename T>
inline bool operator==(const Integer &arr1, const T &number) {
	return CmpArrVST(arr1, number);
}

template<typename T>
inline bool operator!=(const Integer &arr1, const T &number) {
	return !CmpArrVST(arr1, number);
}

template<typename T>
inline std::ostream& operator<<(std::ostream& cout, const Array<T> arr) {
	for (int i = 0; i != length; ++i) {
		cout << arr[i] << " ";
	}
	return;
}