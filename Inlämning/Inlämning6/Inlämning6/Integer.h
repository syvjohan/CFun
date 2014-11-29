#pragma once
#include "Defs.h"

#define NULL 0

//Forward declaration off the class
class Integer;

bool operator<(Integer &lhs, Integer &rhs);
template<typename T>
bool operator<(T &lhs, Integer &rhs);

bool operator>(Integer &lhs, Integer &rhs);
template<typename T>
bool operator>( Integer &lhs, T &rhs);

//template<typename ARRTYPE>
//ARRTYPE operator[](ARRTYPE *arr, Integer<int> index);

class Integer
{
public:
	
	Integer(int number);
	Integer();
	~Integer();

	int GetValue();

	operator int() {
		return someValue;
	}

	//Makes the operators friends to the Integer class. Overlaoding the operators
	template<typename T>
	friend bool operator<(const T &lhs, const Integer &rhs);
	friend bool operator<(const Integer &lhs, const Integer &rhs);

	friend bool operator>(const Integer &lhs, const Integer &rhs);
	template<typename T>
	friend bool operator>(const Integer &lhs, const T &rhs);

	//template<typename ARRTYPE>
	//friend ARRTYPE operator[](ARRTYPE *arr, Integer<int> index);

private:
	int someValue;
	void SetValue(int number);
};

//template<typename ARRTYPE>
//ARRTYPE operator[](ARRTYPE *arr, Integer<int> index) {
//	return arr[index.GetValue()];
//}

Integer::Integer(int number)
{
	SetValue(number);
}

//Default constructor.
Integer::Integer()
{
	someValue = NULL;
}

Integer::~Integer()
{
}

void Integer::SetValue(int number) {
	someValue = number;
	
}

int Integer::GetValue() {
	return someValue;
}

//Check if left hand Integer is less than right hand Integer.
inline bool operator<(const Integer &lhs, const Integer &rhs) {
	return lhs < rhs;
}

//Check if left hand Integer is less than right hand Integer.
inline bool operator>(const Integer &lhs, const Integer &rhs) {
	return operator<(rhs, lhs);
}

//Check if left hand Integer is less than right hand value.
template<typename T>
inline bool operator<(const T &lhs, const Integer &rhs) {
	return lhs < rhs;
}

//Check if left hand value is less than right hand Integer.
template<typename T>
inline bool operator>(const Integer &lhs, const T &rhs) {
	return operator<(rhs, lhs);
}
