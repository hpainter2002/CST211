/*
Hatim Painter
CST 211 Assignment 1
10/8/2015
*/

#include "Book.h"
#include <iostream>
using namespace std;

Book::Book()
{
	m_title = nullptr;
	m_id = 0;
	m_flag = false;
}

Book::Book(char * title, int id, bool flag = false)
{
	m_title = new char[100];
	strcpy_s(m_title, 100, title);
	m_id = id;
	m_flag = flag;
}

Book::Book(char * title, int id)
{
	m_title = new char[100];
	strcpy_s(m_title, 100, title);
	m_id = id;
	m_flag = false;
}

Book::Book(const Book& aCopy)
{
	m_title = new char[100];
	strcpy_s(m_title, 100, aCopy.m_title);
	m_id = aCopy.m_id;
	m_flag = aCopy.m_flag;

	if (aCopy.m_flag == true)
	{
		cout << aCopy.m_title << " is checked out." << endl;
	}
	else
	{
		cout << aCopy.m_title << " is not checked out." << endl;
	}
}

Book::~Book()
{
	delete[]  m_title;
}

char* Book::getTitle() const
{
	return m_title;
}

void Book::setTitle(char *title)
{
	m_title = title;
}

int Book::getId() const
{
	return m_id;
}

void Book::setId(int Id)
{
	m_id = Id;
}

bool Book::getFlag() const
{
	return m_flag;
}

void Book::setFlag(bool flag)
{
	m_flag = flag;
}

bool Book::SameBookMem(const Book & anotherBook)
{
	int TitleCmp = strcmp(m_title, anotherBook.getTitle());
	if (TitleCmp == 0 && m_id == anotherBook.getId())
		return true;
	else
		return false;
}

bool Book::operator!=(const Book & anotherBook)
{
	int TitleCmp = strcmp(m_title, anotherBook.getTitle());
	if (TitleCmp == 0 && m_id == anotherBook.getId())
		return true;
	else
		return false;
}

Book & Book::operator=(const Book& oneBook)
{
	/*m_title = new char[strlen(oneBook.m_title)];
	strcpy_s(m_title, strlen(oneBook.m_title), oneBook.m_title);*/

	m_title = new char[100];
	strcpy_s(m_title, 100, oneBook.m_title);

	m_id = oneBook.getId();
	m_flag = oneBook.getFlag();


	return *this;

}

Book & Book::operator--() //prefix
{
	m_flag = true;

	return *this;
}

Book & Book::operator++() //prefix
{
	m_flag = false;

	return *this;
}

void Book::Display() const
{
	cout << "Title: " << m_title << " " << "Id: " << m_id << " " << "Checked out: " << m_flag << endl;
}

