#pragma once
#include "Book.h"

class Library
{
public:
	Library();
	~Library();
	bool search_by_title();
	bool search_by_publisher();
	bool search_by_ISBN();
	bool addBookToLibrary(std::ifstream& fin);
	void printBooksFromLibrary();
	bool verifyISBN();
	void menu(int, std::ifstream&);
	void options();

private:
	Book books[11];
	int noBooksAdded;

};