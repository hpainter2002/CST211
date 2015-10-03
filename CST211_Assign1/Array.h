#pragma once

#include <iostream>
#include "Exception.h"

using namespace std;

template <typename T>
class Array
{
public:
	Array();
	Array(int length, int start_index = 0);
	Array(const Array & aCopy);
	~Array();

	Array<T> & Array<T>::operator =(const Array & anArray);
	T & operator [](int index);

	int getStartIndex();
	void setStartIndex(int start_index);
	int getLength();
	void setLength(int length);

private:
	T * m_myArray;
	int m_length;
	int m_start_index;
};

template <typename T>
Array<T>::Array()
{
	m_myArray = nullptr;
	m_length = 0;
	m_start_index = 0;

	cout << "Default ctor called!" << endl;
}

template <typename T>
Array<T>::Array(int length, int start_index)
{
	m_myArray = new T[length];
	m_length = length;
	m_start_index = start_index;

	cout << "Non-default ctor called!" << endl;
}

template <typename T>
Array<T>::Array(const Array<T> & aCopy)
{
	m_myArray = new T[aCopy.m_length];

	for (int i = 0; i < aCopy.m_length; i++)
	{
		m_myArray[i] = aCopy.m_myArray[i];
	}

	m_length = aCopy.m_length;
	m_start_index = aCopy.m_start_index;

	cout << "Copy ctor called!" << endl;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_myArray;

	cout << "Destructor called!" << endl;
}

template <typename T>
Array<T> & Array<T>::operator =(const Array<T> & anArray)
{
	
	m_myArray = new T[anArray.m_length];

	for (int i = 0; i < anArray.m_length; i++)
	{
		m_myArray[i] = anArray.m_myArray[i];
	}

	m_length = anArray.m_length;
	m_start_index = anArray.m_start_index;

	cout << "Assignment operator called!" << endl;

	return *this;
}

template <typename T>
T & Array<T>::operator [](int index)
{
	cout << "Subscript operator called!" << endl;

	return m_myArray[index];
	
}

template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::getLength()
{
	return m_length;
}

template <typename T>
void Array<T>::setLength(int length)
{
	m_length = length;
}