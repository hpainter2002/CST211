#pragma once

#include <iostream>
using namespace std;

class Exception
{
	friend std::ostream& operator<<(std::ostream & str, const Exception & anException);

public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & aCopy);
	~Exception();
	Exception & operator =(const Exception & anException);
	const char * getMessage();
	void setMessage(char * msg);
	
private:
	char* m_msg;
};

