/*
Hatim Painter
CST 211 Assignment 2
10/8/2015
*/

#pragma once

#include "Row.h"

template <typename T>
class Array2D
{
public:
	Array2D();										// Default constructor
	Array2D(int row, int col = 0);					// Constructs a 2D array of specified rows and columns
	Array2D(const Array2D<T> & aCopy);				// Copy constructor
	~Array2D();										// Destrcutor

	Array2D<T> & operator =(Array2D<T> & anArray);	// Overloaded assignment operator
	Row<T> operator [](int index);					// Overloaded subscript operator

	int getRow() const;								// Returns current number of rows in the array
	void setRow(int rows);							// Sets the rows of the array to desired size
	int getColumn() const;							// Returns current number of columns in the array
	void setColumn(int columns);					// Sets the columns of the array to the desired size
	T & Select(int row, int column) const;			// Returns data from the desired cell when a row and a column is specified
	void display() const;							// Displays the contents of the array

private:
	T** m_array;
	int m_row;
	int m_col;
};

#include "Array2D.cpp"