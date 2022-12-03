#include <iostream>
#include "Library.h"
#include "ISBN.h"

Library::Library()
{
	noBooksAdded = 0;
}

Library::~Library()
{

}

bool Library::addBookToLibrary(std::ifstream& fin)
{
	return books[noBooksAdded++].addBook(fin);
}

void Library::printBooksFromLibrary()
{
	for (int i = 0; i < noBooksAdded; i++)
		books[i].printBook();
}

bool Library::verifyISBN()
{
	std::string countryISBNCurrent, publisherISBNCurrent, titleISBNCurrent, digitISBNCurrent;
	std::string countryISBN, publisherISBN, titleISBN, digitISBN;

	for (int i = 0; i < noBooksAdded - 1; i++)
	{
		books[i].getISBN(countryISBN, publisherISBN, titleISBN, digitISBN);
		books[noBooksAdded - 1].getISBN(countryISBNCurrent, publisherISBNCurrent, titleISBNCurrent, digitISBNCurrent);
		if (countryISBN == countryISBNCurrent && publisherISBN == publisherISBNCurrent && titleISBN == titleISBNCurrent && digitISBN == digitISBNCurrent)
			return false;
	}

	return true;
}

void Library::menu(const int maxSize, std::ifstream& fin)
{
	int noOfBooks;
	
	fin >> noOfBooks; 
	fin.ignore();
	fin.get();
	
	const int maxSizeFile = noOfBooks;

	int opt = -1;

	while (opt != 7)
	{

		options();
		std::cin >> opt;

		switch (opt)
		{
		case 1:
			system("cls");
			if (noBooksAdded == maxSize || noBooksAdded == maxSizeFile)
			{
				std::cout << "You can't add books! Check dimension!\n";
				break;
			}

			addBookToLibrary(fin);
			if (verifyISBN() == false)
			{
				std::cout << "This ISBN is used for another book! Check the input file! Error on position: " << noBooksAdded << "\n";
				exit(1);
			}
			break;
		case 2:
			system("cls");
			if (noBooksAdded == maxSize || noBooksAdded == maxSizeFile)
			{
				std::cout << "You can't add books! Check dimension!\n";
				break;
			}
			while(maxSizeFile - noBooksAdded)
			{
				addBookToLibrary(fin);
				if (verifyISBN() == false)
				{
					std::cout << "This ISBN is used for another book! Check the input file! Error on position: " << noBooksAdded << "\n";
					exit(1);
				}
			}
			break;
		case 3:
			system("cls");
			printBooksFromLibrary();
			break;

		case 4:
			system("cls");
			search_by_title();
			break;

		case 5:
			system("cls");
			search_by_publisher();
			break;

		case 6:
			system("cls");
			search_by_ISBN();
			break;

		case 7:
			break;

		default:
			system("cls");
			std::cout << "Invalid option!\n\n";
			break;
		}

	}
}

void Library::options()
{
	std::cout << "1. Add a book\n";
	std::cout << "2. Add all books\n";
	std::cout << "3. Prints all the books\n";
	std::cout << "4. Search a book by title\n";
	std::cout << "5. Search a book by publisher\n";
	std::cout << "6. Search a book by ISBN\n";
	std::cout << "7. Exit menu" << "\n";
	std::cout << "Your option: ";
}

bool  Library::search_by_title()
{
	int i;
	std::string myString;

	std::cin.get();
	std::cout << "Title to search: ";  getline(std::cin, myString);

	for (i = 0; i < noBooksAdded; i++)
		if (books[i].getTitle() == myString)
		{
			std::cout << "Book found!\n\n";
			books[i].printBook();
			return true;
		}

	std::cout << "Book not found!\n\n";
	return false;
}

bool Library::search_by_publisher()
{
	int i;
	std::string str;

	bool ok = false;

	std::cin.get();
	std::cout << "Publisher to search: ";  getline(std::cin, str);

	std::cout << "Books by " << str << " publisher: \n\n";
	for (i = 0; i < noBooksAdded; i++)
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

bool  Library::search_by_ISBN()
{
	int i;
	std::string strISBN;

	std::cin.get();
	std::cout << "ISBN to search: ";  getline(std::cin, strISBN);

	std::string countryISBNIn, publisherISBNIn, titleISBNIn, digitISBNIn;
	std::string countryISBN, publisherISBN, titleISBN, digitISBN;

	books[noBooksAdded].computeISBN(strISBN, countryISBNIn, publisherISBNIn, titleISBNIn, digitISBNIn);

	for (i = 0; i < noBooksAdded; i++)
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



