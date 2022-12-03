#include "Book.h"
#include "Library.h"
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

Book::Book()
{
	title = "";
	author = "";
	publisher = "";
	publishing_year = 0;
	price = 0.0;
}

Book::~Book() {};

bool Book::addBook(std::ifstream& fin)
{

	time_t now = time(0);
	int year = 1970 + now / 31556926;


	if (fin.peek() == EOF)
	{
		std::cout << "You reached the end of the file!\n\n";
		return false;
	}

	std::string strISBN, countryISBN, publisherISBN, titleISBN, digitISBN;

	getline(fin, this->title);
	getline(fin, this->author);
	getline(fin, this->publisher);
	getline(fin, strISBN);

	this->computeISBN(strISBN, countryISBN, publisherISBN, titleISBN, digitISBN);

	if (digitISBN.size() > 0)
		isbn = new ISBN(countryISBN, publisherISBN, titleISBN, digitISBN);
	else
		isbn = new ISBN(countryISBN, publisherISBN, titleISBN);

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

	std::cout << "Book successfully added from file!\n";

	fin.get();
	fin.get();

	return true;
}


void Book::printBook()
{
	std::cout << this->title << "\n";
	std::cout << this->author << "\n";
	std::cout << this->publisher << "\n";
	isbn->printISBN();
	std::cout << this->publishing_year << "\n";
	std::cout << this->price << "\n";

	std::cout << "\n";
}

const std::string Book::getTitle()
{
	return this->title;
}

const std::string Book::getAuthor()
{
	return this->author;
}

const std::string Book::getPublisher()
{
	return this->publisher;
}

void Book::computeISBN(std::string myString, std::string& country, std::string& publisher, std::string& title, std::string& digit)
{
	std::istringstream iss(myString);
	std::string token;

	int opt = 1;

	while (std::getline(iss, token, '-'))
	{
		switch (opt)
		{
		case 1:
			country = token;
			opt++;
			break;
		case 2:
			publisher = token;
			opt++;
			break;
		case 3:
			title = token;
			opt++;
			break;
		case 4:
			digit = token;
			opt++;
			break;
		}
	}

	if (digit == "")
		digit = isbn->computeCheckDigit(country, publisher, title);

}

const void Book::getISBN(std::string& countryIdf, std::string& publisherIdf, std::string& titleIdf, std::string& digitIdf)
{
	countryIdf = isbn->getCountryIdentidier();
	publisherIdf = isbn->getPublisherIdentifier();
	titleIdf = isbn->getTitleIdentifier();
	digitIdf = isbn->getCheckDigit();
}