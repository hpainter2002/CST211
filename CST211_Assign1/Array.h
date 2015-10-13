/*
Hatim Painter
CST 211 Assignment 1
10/8/2015
*/

#pragma once

#include <iostream>
#include "Exception.h"

using namespace std;

template <typename T>
class Array
{
public:
	Array();										// Default constructor
	Array(int length, int start_index = 0);			// Constructs an array of specified length wiht start index defaulted to 0
	Array(const Array & aCopy);						// Copy constructor
	~Array();										// Destructor

	Array<T> & operator =(const Array & anArray);	// Overloaded assignment operator
	T & operator [](int index);						// Overloaded subscript operator

	int getStartIndex();							// Returns the current start index
	void setStartIndex(int start_index);			// Sets the start index to an integer value
	int getLength();								// Returns the length of the array
	void setLength(int length);						// Changes the length of the array to the specified length
	void display() const;							// Displays the array

private:
	T * m_myArray;
	int m_length;
	int m_start_index;
};

#include "Array.cpp"
