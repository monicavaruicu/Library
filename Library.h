#pragma once
#include <iostream>
#include <fstream>

class Library
{
public:
	Library();
	int addBook(std::ifstream &fin);
	void printBook();
	const std::string getTitle();
	const std::string getPublisher();
	const std::string getISBN();
	int search_by_title(Library myObj[], int myObjSize);
	int search_by_publisher(Library myObj[], int myObjSize);
	int search_by_ISBN(Library myObj[], int myObjSize);
	~Library();


private:
	std::string title;
	std::string author;
	std::string publisher;
	std::string ISBN;
	int publishing_year;
	float price;
};
