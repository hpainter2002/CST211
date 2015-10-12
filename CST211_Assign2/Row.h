/*
Hatim Painter
CST 211 Assignment 2
10/8/2015
*/

#pragma once

template <typename T>
class Array2D;

template <typename T>
class Row
{
public:
	Row(Array2D<T> & array, int row);			// Constructs the Row object
	T & operator [](int column);				// Overloaded subscript operator

private:
	Array2D<T> & m_array2D;
	int m_row;
};

#include "Row.cpp"