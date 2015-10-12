/*********************************************************************************************
* Author:					Hatim Painter
* Date Created:				10/8/2015
* Last Modification Date:	10/11/2015
* Lab Number:				CST 211 Assignment 2
* Instructor:				Joshua Kimball
* Included Files:
*	Source.cpp
*	Array2D.h
*	Array2D.cpp
*	Row.h
*	Row.cpp
*	Exception.h
*	Exception.cpp
*
* Overview:
*	This program will create a templated 2D array class. Which can be used to create array of any
*	kind of objects or classes.
*
***********************************************************************************************/

#include <iostream>
#include "Array2D.h"
#include "Row.h"
#include "Exception.h"

using std::cout;
using std::endl;

int main()
{
	try
	{
		Array2D<int> board(3, 3);

		for (int i = 0; i < board.getRow(); i++)
		{
			for (int k = 0; k < board.getColumn(); k++)
			{
				board[i][k] = (i + 1) * 10;
			}
		}

		// Copy constructor test
		cout << "Displaying board:" << endl;
		board.display();

		cout << "Creating a copy boardCopy using copy constructor." << endl;
		Array2D<int> boardCopy(board);    //create a copy 
		cout << "Displaying boardCopy after using copy constructor" << endl;
		boardCopy.display();

		// Assignment operator test
		Array2D<int> boardAssign;				// Default constructor used

		cout << "Assignment Operator test:" << endl;
		cout << "Displaying board:" << endl;
		board.display();
		boardAssign = board;

		cout << "Displaying boardAssign after using assignment on it:" << endl;
		boardAssign.display();

		//getRow() test
		cout << "Method Test: getRow()" << endl;
		cout << "Row is: " << board.getRow() << endl << endl;

		//setRow() test
		cout << "Method Test: setRow(5)" << endl;
		board.setRow(5);
		cout << "Ater set row..." << endl;
		cout << "Row is: " << board.getRow() << endl << endl;
		cout << "Displaying board:" << endl;
		board.display();

		//getColumn() test
		cout << "Method Test: getColumn()" << endl;
		cout << "Column is: " << board.getColumn() << endl << endl;

		//setColumn() test
		cout << "Method Test: setColumn(2)" << endl;
		board.setColumn(2);
		cout << "Ater set column..." << endl;
		cout << "Column is: " << board.getRow() << endl << endl;
		cout << "Displaying board:" << endl;
		board.display();

		// Testing exception  class
		cout << "Exception tests (uncomment to test the exceptions):" << endl;

		//// Row upper bound exception test
		//cout << "board[7][1] = 13" << endl;
		//board[7][1] = 13;

		//// Row lower bound exception test
		//cout << "board[-4][1] = 54" << endl;
		//board[-4][1] = 54;

		//// Column upper bound exception test
		//cout << "board[7][1] = 13" << endl;
		//board[2][8] = 13;

		//// Column lower bound exception test
		//cout << "board[-4][1] = 54" << endl;
		//board[2][-2] = 54;

		////SetRow Exception Test
		//board.setRow[-4][1];

		////SetColumn Exception test
		//board.setColumn[2][-3];
	}

	catch (Exception & except)
	{
		cout << except.getMessage() << endl;
	}
	

	return 0;
}