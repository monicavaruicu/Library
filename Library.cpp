#include <iostream>
#include "Library.h"
#include "ISBN.h"

bool Library::addBookToLibrary(int& myObjSize, std::ifstream& fin)
{
	return books[myObjSize++].addBook(fin);
}

void Library::printBooksFromLibrary(int myObjSize)
{
	for (int i = 0; i < myObjSize; i++)
		books[i].printBook();
}

bool Library::verifyISBN(int myObjSize)
{
	std::string countryISBNCurrent, publisherISBNCurrent, titleISBNCurrent, digitISBNCurrent;
	std::string countryISBN, publisherISBN, titleISBN, digitISBN;

	for (int i = 0; i < myObjSize - 1; i++)
	{
		books[i].getISBN(countryISBN, publisherISBN, titleISBN, digitISBN);
		books[myObjSize - 1].getISBN(countryISBNCurrent, publisherISBNCurrent, titleISBNCurrent, digitISBNCurrent);
		if (countryISBN == countryISBNCurrent && publisherISBN == publisherISBNCurrent && titleISBN == titleISBNCurrent && digitISBN == digitISBNCurrent)
			return false;
	}

	return true;
}


bool  Library::search_by_title(int myObjSize)
{
	int i;
	std::string myString;

	std::cin.get();
	std::cout << "Title to search: ";  getline(std::cin, myString);

	for (i = 0; i < myObjSize; i++)
		if (books[i].getTitle() == myString)
		{
			std::cout << "Book found!\n\n";
			books[i].printBook();
			return true;
		}

	std::cout << "Book not found!\n\n";
	return false;
}

bool Library::search_by_publisher(int myObjSize)
{
	int i;
	std::string str;

	bool ok = false;

	std::cin.get();
	std::cout << "Publisher to search: ";  getline(std::cin, str);

	std::cout << "Books by " << str << " publisher: \n\n";
	for (i = 0; i < myObjSize; i++)
		if (books[i].getPublisher() == str)
		{
			books[i].printBook();
			std::cout << "\n";
			ok = true;
		}

	if (ok == false)
		std::cout << "No book with this publisher was found!\n\n";

	return ok;
}

bool  Library::search_by_ISBN(int myObjSize)
{
	int i;
	std::string strISBN;

	std::cin.get();
	std::cout << "ISBN to search: ";  getline(std::cin, strISBN);

	std::string countryISBNIn, publisherISBNIn, titleISBNIn, digitISBNIn;
	std::string countryISBN, publisherISBN, titleISBN, digitISBN;

	books[myObjSize].computeISBN(strISBN, countryISBNIn, publisherISBNIn, titleISBNIn, digitISBNIn);

	for (i = 0; i < myObjSize; i++)
	{
		books[i].getISBN(countryISBN, publisherISBN, titleISBN, digitISBN);
		if (countryISBN == countryISBNIn && publisherISBN == publisherISBNIn && titleISBN == titleISBNIn && digitISBN == digitISBNIn)
		{
			std::cout << "ISBN found!\n\n";
			books[i].printBook();
			return true;
		}
	}

	std::cout << "ISBN not found!\n\n";
	return false;
}



