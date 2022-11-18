#include <fstream>
#include "Library.h"
#include "Menu.h"
#define size 50

std::ifstream fin("Books.in");

int main()
{
	Library lbr;

	int noBooksAdded = 0;
	int noOfBooks;

	fin >> noOfBooks; fin.ignore();
	fin.get();

	menu(lbr, noBooksAdded, size, noOfBooks, fin);

	fin.close();
	return 0;
}

