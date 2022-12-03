#include <fstream>
#include "Library.h"
#define size 50

std::ifstream fin("Books.in");

int main()
{
	Library lbr;

	lbr.menu(size, fin);

	fin.close();

	return 0;
}

