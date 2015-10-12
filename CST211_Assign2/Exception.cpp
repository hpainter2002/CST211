/*
Hatim Painter
CST 211 Assignment 2
10/8/2015
*/

#include "Exception.h"

ostream & operator <<(ostream & str, const Exception & anException);

Exception::Exception()
{
	m_msg = nullptr;
}

Exception::Exception(char * msg)
{
	m_msg = new char[strlen(msg) + 1];
	m_msg = msg;
}

Exception::Exception(const Exception & aCopy)
{
	m_msg = new char[strlen(aCopy.m_msg) + 1];
	m_msg = aCopy.m_msg;
}

Exception::~Exception()
{
	delete[] m_msg;
}

Exception & Exception::operator = (const Exception & anException)
{
	m_msg = new char[strlen(anException.m_msg) + 1];
	m_msg = anException.m_msg;

	return *this;
}

const char * Exception::getMessage()
{
	return m_msg;
}

void Exception::setMessage(char * msg)
{
	m_msg = msg;
}

ostream & operator <<(ostream & str, const Exception & anException)
{
	cout << anException.m_msg << endl;

	return str;
}