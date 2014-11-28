#pragma once
#include "Defs.h"
#include "Array.h"

#define NULL 0

//Forward declaration off the class
template<typename T>
class Number;

template<typename T>
class Array;

template<typename T>
bool operator<(Number<T> &lhs, Number<T> &rhs);

template<typename T>
bool operator<(Number<T> &lhs, T &rhs);

template<typename T>
bool operator>(Number<T> &lhs, Number<T> &rhs);

template<typename T>
bool operator>( T &lhs, Number<T> &rhs);

template<typename T>
bool operator<(Number<T> &lhs, T &rhs);

template<typename T>
class Number
{
	template<typename T>
	friend class Array;
public:
	
	Number<T>(T number);
	Number<T>();
	~Number<T>();

	T GetValue();

	//Makes the operators friends to the Number class. Overlaoding the operators
	template<typename T>
	friend bool operator<(const Number<T> &lhs, const T &rhs);
	friend bool operator<(const Number<T> &lhs, const Number<T> &rhs);

	friend bool operator>(const Number<T> &lhs, const Number<T> &rhs);
	template<typename T>
	friend bool operator>(const T &lhs, const Number<T> &rhs);

private:
	int someValue;
	void SetValue(T number);
};

template<typename T>
Number<T>::Number(T number)
{
	SetValue(number);
}

//Default constructor.
template<typename T>
Number<T>::Number()
{
	someValue = NULL;
}

template<typename T>
Number<T>::~Number()
{
}

template<typename T>
void Number<T>::SetValue(T number) {
	someValue = number;
	
}

//Check if left hand Number is less than right hand Number.
template<typename T>
inline bool operator<(const Number<T> &lhs, const Number<T> &rhs) {
	return lhs < rhs;
}

//Check if left hand Number is less than right hand Number.
template<typename T>
inline bool operator>(const Number<T> &lhs, const Number<T> &rhs) {
	return operator<(rhs, lhs);
}

//Check if left hand Number is less than right hand value.
template<typename T>
inline bool operator<(const Number<T> &lhs, const T &rhs) {
	return lhs < rhs;
}

//Check if left hand value is less than right hand Number.
template<typename T>
inline bool operator>(const T &lhs, const Number<T> &rhs) {
	return operator<(rhs, lhs);
}
