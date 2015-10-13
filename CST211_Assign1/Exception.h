/*
Hatim Painter
CST 211 Assignment 1
10/8/2015
*/

#pragma once

#include <iostream>
using namespace std;

class Exception
{
	friend std::ostream& operator<<(std::ostream & str, const Exception & anException);

public:
	Exception();												// Default constructor
	Exception(char * msg);										// Constructs the object with a message
	Exception(const Exception & aCopy);							// Copy constructor
	~Exception();												// Destructor
	Exception & operator =(const Exception & anException);		// Overloaded assignment operator 
	const char * getMessage();									// Returns the message passed in when the object was constructed
	void setMessage(char * msg);								// Sets the message to desired message
	
private:
	char* m_msg;
};

