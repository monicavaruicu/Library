#include <iostream>
#include <fstream>
#include "Library.h"
#include <string>
#define size 11

std::ifstream fin("Books.in");

int main()
{

	Library lbr[size];
	Library fct;

	int opt = 1;
	int lbrSize = 0;
	
	std::string str;
	std::string a;

	int noOfBooks = 0;
	fin >> noOfBooks;
	
	fin.get();
	fin.get();


	while (opt != 0)
	{
		std::cout << "1. Add a book\n";
		std::cout << "2. Prints all the books\n";
		std::cout << "3. Search a book by title\n";
		std::cout << "4. Search a book by publisher\n";
		std::cout << "5. Search a book by ISBN\n";

		std::cout << "Option: "; std::cin >> opt;

		switch (opt)
		{
		case 1:
			system("cls");
			if (lbrSize == size || lbrSize == noOfBooks)
			{
				std::cout << "You can't add books! Check dimension!\n";
				break;
			}
			
			lbr[lbrSize++].addBook(fin);
			break;

		case 2:
			system("cls");
			for (int i = 0; i < lbrSize; i++)
				lbr[i].printBook();
			break;

		case 3:
			system("cls");
			fct.search_by_title(lbr, lbrSize);
			break;

		case 4:
			system("cls");
			fct.search_by_publisher(lbr, lbrSize);
			break;

		case 5:
			system("cls");
			fct.search_by_ISBN(lbr, lbrSize);
			break;

		default:
			system("cls");
			std::cout << "Invalid option!\n\n";
			break;
		}
	}

	return 0;
}
