#pragma once
#include <fstream>
#include "ISBN.h"

class Book
{
public:
	Book();
	bool addBook(std::ifstream& fin);
	void printBook();
	void computeISBN(std::string, std::string&, std::string&, std::string&, std::string&);
	const std::string getTitle();
	const std::string getAuthor();
	const std::string getPublisher();
	const void getISBN(std::string&, std::string&, std::string&, std::string&);
	~Book();


private:
	std::string title;
	std::string author;
	std::string publisher;
	ISBN* isbn;
	int publishing_year;
	float price;
};

