#include <iostream>
#include "Array.h"
#include "Exception.h"
#include "Book.h"

using namespace std;

int main()
{
	
	Array<int> intArray(10);           //create an int array 
	Array<Book> bookArray(10);

	// Assignment operator test
	Array<int> intArray4(5);
	Array<int> intArray5;

	intArray5 = intArray4;

	intArray[0] = 5;
	cout << intArray[0] << endl;
	intArray[1] = 7;
	cout << intArray[1] << endl;

	////same as intArray[2] = 20; intArray[3] = 10; 
	intArray[4] = 8;
	intArray[5] = 9;
	intArray[6] = 10;
	intArray[7] = 11;
	intArray[8] = 12;
	try
	{
		intArray[12] = 13;

	}
	catch (Exception & except)
	{
		cout << except.getMessage() << endl;
	}
	

	Array<int> intArray2(intArray);    //create a copy 

	Array<int> intArray3 = intArray;
	

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