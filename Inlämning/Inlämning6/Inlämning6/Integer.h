#pragma once
#include "Defs.h"

#define NULL 0

//Forward declaration off the class
template<typename T>
class Integer;

template<typename T>
bool operator<(Integer<T> &lhs, Integer<T> &rhs);

template<typename T>
bool operator>(Integer<T> &lhs, Integer<T> &rhs);

template<typename T>
bool operator<( Integer<T> &lhs, T &rhs);

template<typename T>
bool operator>( T &lhs, Integer<T> &rhs);

template<typename T>
class Integer
{
public:
	Integer<T>(T number = NULL); // = NUll. combining a default constructor and a constructor with one element.
	~Integer<T>();

	Integer<T> SetValue(T number);

	//Makes the operators friend to the Integer class
	friend bool operator<(const Integer<T> &lhs, const Integer<T> &rhs);
	friend bool operator>(const Integer<T> &lhs, const Integer<T> &rhs);
	friend bool operator<(const Integer<T> &lhs, const T &rhs);
	friend bool operator>(const T &lhs, const Integer<T> &rhs);

private:
	int value;
};


template<typename T>
Integer<T>::Integer(T number)
{
	this->value = number;
}

template<typename T>
Integer<T>::~Integer()
{
}

template<typename T>
Integer<T> Integer<T>::SetValue(T number) {
	return this->value = number;
}

//Check if left hand Integer is less than right hand Integer.
template<typename T>
inline bool operator<(const Integer<T> &lhs, const Integer<T> &rhs) {
	return lhs < rhs;
}

//Check if left hand Integer is less than right hand Integer.
template<typename T>
inline bool operator>(const Integer<T> &lhs, const Integer<T> &rhs) {
	return operator<(rhs, lhs);
}

//Check if left hand Integer is less than right hand value.
template<typename T>
inline bool operator<(const Integer<T> &lhs, const T &rhs) {
	return lhs < rhs;
}

//Check if left hand value is less than right hand Integer.
template<typename T>
inline bool operator>(const T &lhs, const Integer<T> &rhs) {
	return operator<(rhs, lhs);
}

