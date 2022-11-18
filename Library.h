#pragma once
#include "Book.h"

class Library
{
public:
	bool search_by_title(int myObjSize);
	bool search_by_publisher(int myObjSize);
	bool search_by_ISBN(int myObjSize);
	bool addBookToLibrary(int& myObjSize, std::ifstream& fin);
	void printBooksFromLibrary(int myObjSize);
	bool verifyISBN(int myObjSize);

private:
	Book books[11];

};