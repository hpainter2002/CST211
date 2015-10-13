/*
Hatim Painter
CST 211 Assignment 1
10/8/2015
*/

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
 
// Book class is to test the templated array's capabilities on handling objects
class Book
{
public:
	friend std::istream & operator>>(std::istream & str, Book & oneBook);
	friend std::ostream& operator<<(std::ostream & str, const Book & oneBook);

	Book();
	Book(char * title, int id, bool flag);
	Book(char * title, int id);
	Book(const Book& aCopy);
	bool SameBookMem(const Book & anotherBook);
	bool operator!=(const Book & anotherBook);
	Book & operator=(const Book& oneBook);
	Book & operator>>(Book & oneBook);
	Book & operator<<(const Book & oneBook);
	Book & operator--(); //prefix
	Book & operator++(); //prefix
	void Display() const;
	char *getTitle() const;
	void setTitle(char *title);
	int getId() const;
	void setId(int Id);
	bool getFlag() const;
	void setFlag(bool flag);

	~Book();

private:
	char *m_title;
	int m_id;
	bool m_flag;

};

#endif