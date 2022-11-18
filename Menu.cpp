#include <iostream>
#include "Menu.h"


void menu(Library myObj, int myObjSize, const int maxSize, int maxSizeFile, std::ifstream& fin)
{
	int opt = 1;

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
			if (myObjSize == maxSize || myObjSize == maxSizeFile)
			{
				std::cout << "You can't add books! Check dimension!\n";
				break;
			}

			myObj.addBookToLibrary(myObjSize, fin);
			if (myObj.verifyISBN(myObjSize) == false)
			{
				std::cout << "This ISBN is used for another book! Check the input file! Error on position: " << myObjSize << "\n";
				exit(1);
			}
			break;

		case 2:
			system("cls");
			myObj.printBooksFromLibrary(myObjSize);
			break;

		case 3:
			system("cls");
			myObj.search_by_title(myObjSize);
			break;

		case 4:
			system("cls");
			myObj.search_by_publisher(myObjSize);
			break;

		case 5:
			system("cls");
			myObj.search_by_ISBN(myObjSize);
			break;

		default:
			system("cls");
			std::cout << "Invalid option!\n\n";
			break;
		}

	}
}