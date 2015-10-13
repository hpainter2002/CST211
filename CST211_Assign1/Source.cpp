/*********************************************************************************************
* Author:					Hatim Painter
* Date Created:				10/8/2015
* Last Modification Date:	10/8/2015
* Lab Number:				CST 211 Assignment 1
* Instructor:				Joshua Kimball
* Included Files:
*	Source.cpp
*	Array.h
*	Array.cpp
*	Exception.h
*	Exception.cpp
*	Book.h
*	Book.cpp
*
* Overview:
*	This program will create a templated array class. Which can be used to create array of any
*	kind of objects or classes.
*
***********************************************************************************************/

#include <iostream>
#include "Array.h"
#include "Exception.h"
#include "Book.h"

using namespace std;

int main()
{
	
	Array<int> intArray(10);			// Create an array of ints  
	
	// Fill the array 
	for (int i = 0; i < intArray.getLength(); i++)
	{
		intArray[i] = (i + 1) * 10;
	}
	
	// Copy constructor test
	cout << "Displaying intArray:" << endl;
	intArray.display();

	cout << "Creating a copy intArray2 using copy constructor." << endl;
	Array<int> intArray2(intArray);    //create a copy 
	cout << "Displaying intArray2 after using copy constructor" << endl;
	intArray2.display();

	Array<int> intArray3 = intArray;
	
	// Assignment operator test
	Array<int> intArray4(5);
	Array<int> intArray5;				// Default constructor used

	for (int i = 0; i < intArray4.getLength(); i++)
	{
		intArray4[i] = (i + 1) * 20;
	}

	cout << "Assignment Operator test:" << endl;
	cout << "Displaying intArray4:" << endl;
	intArray4.display();
	intArray5 = intArray4;				

	cout << "Displaying intArray5 after using assignment on it:" << endl;
	intArray5.display();

	//getStartIndex() test
	cout << "Method Test: getStartIndex()" << endl;
	cout << "Start index is: " << intArray.getLength() << endl;

	//setStartIndex() test
	cout << endl << "Method Test: setStartIndex(7)" << endl;
	intArray.setStartIndex(7);
	cout << "Ater set start index:" << endl;
	cout << "Start index is: " << intArray.getStartIndex() << endl;

	//getLength() test
	cout << endl << "Method Test: getLength()" << endl;
	cout << "Length of the array is: " << intArray.getLength() << endl;

	// setLength() test
	cout << endl << "Method Test: setLength(5)" << endl;
	intArray.setLength(5);
	cout << "After set length:" << endl;
	cout << "Length of the array is: " << intArray.getLength() << endl << endl;

	// Testing exception  class
	cout << "Exception test (uncomment to test the exceptions):" << endl;

	//// Upper bound test
	//try
	//{
	//	cout << "intArray[12] = 13" << endl;
	//	intArray[12] = 13;

	//}
	//catch (Exception & except)
	//{
	//	cout << except.getMessage() << endl;
	//}
	//
	//// Lower bound test
	//try
	//{
	//	cout << "intArray[-4] = 54" << endl;
	//	intArray[-4] = 54;

	//}
	//catch (Exception & except)
	//{
	//	cout << except.getMessage() << endl;
	//}
	
	Array<Book> bookArray(10);			// Create an array of Book objects	

	Book book1("Petzlod", 100, false);	
	Book book2("Albert", 101, true);
	Book book3("Breedlove", 102, false);
	Book book4("Meyers", 103);

	bookArray[0] = book1;
	bookArray[1] = book2;
	bookArray[2] = book3;
	bookArray[3] = book4;

	return 0;
	
}