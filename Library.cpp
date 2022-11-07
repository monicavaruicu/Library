#include "Library.h"
#include <string>
#include <chrono>

Library::Library()
{
	title = "";
	author = "";
	publisher = "";
	ISBN = "";
	publishing_year = 0;
	price = 0.0;
}

Library::~Library()
{
}

int Library::addBook(std::ifstream &fin)
{

	time_t now = time(0);
	int year = 1970 + now/31556926;


	if (fin.peek() == EOF)
	{
		std::cout << "You reached the end of the file!\n\n";
		return 0;
	}

	getline(fin, this->title);
	getline(fin, this->author);
	getline(fin, this->publisher);
	getline(fin, this->ISBN);

	int x;
	fin >> x;
	
	if (x > year || x < 0)
	{
		std::cout << "Couldn't assign the value";
		exit(1);
	}
	else
		this->publishing_year = x;

	float y;
	fin >> y;
	
	if (y < 0)
	{
		std::cout << "Couldn't assign the value";
		exit(1);
	}
	else
		this->price = y;

	std::cout << "Book successfully added from file!\n\n";

	fin.get();
	fin.get();

	return 1;
}

void Library::printBook()
{
	std::cout << this->title << "\n";
	std::cout << this->author << "\n";
	std::cout << this->publisher << "\n";
	std::cout << this->ISBN << "\n";
	std::cout << this->publishing_year << "\n";
	std::cout << this->price << "\n";

	std::cout << "\n";
}

int  Library::search_by_title(Library myObj[], int myObjSize)
{
	int i;
	std::string str;

	std::cin.get();
	std::cout << "Title to search: ";  getline(std::cin, str);
	for (i = 0; i < myObjSize; i++)
		if (myObj[i].getTitle() == str)
		{
			std::cout << "Book found!\n\n";
			return 1;
		}

	std::cout << "Book not found!\n\n";
	return 0;
}

int  Library::search_by_publisher(Library myObj[], int myObjSize)
{
	int i;
	std::string str;

	int ok = 0;

	std::cin.get();
	std::cout << "Publisher to search: ";  getline(std::cin, str);

	std::cout << "Books by " << str << " publisher: \n\n";
	for (i = 0; i < myObjSize; i++)
		if (myObj[i].getPublisher() == str)
		{
			std::cout << myObj[i].getTitle() << "\n";
			ok = 1;
		}

	if (ok == 0)
		std::cout << "No book with this publisher was found!\n\n";

	std::cout << "\n";

	return ok;
}

int  Library::search_by_ISBN(Library myObj[], int myObjSize)
{
	int i;
	std::string str;

	std::cin.get();
	std::cout << "ISBN to search: ";  getline(std::cin, str);

	for (i = 0; i < myObjSize; i++)
		if (myObj[i].getISBN() == str)
		{
			std::cout << myObj[i].getTitle() << "\n\n";
			return 1;
		}

	std::cout << "ISBN not found!\n\n";

	return 0;
}

const std::string Library::getTitle()
{
	return this->title;
}

const std::string Library::getPublisher()
{
	return this->publisher;
}

const std::string Library::getISBN()
{
	return this->ISBN;
}

