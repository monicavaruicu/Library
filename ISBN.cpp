#include <iostream>
#include "ISBN.h"

ISBN::ISBN()
{
	countryIdentifier = "";
	publisherIdentifier = "";
	titleIdentifier = "";
	checkDigit = "";
}

ISBN::~ISBN() {};

ISBN::ISBN(std::string country, std::string publisher, std::string title)
{
	countryIdentifier = country;
	publisherIdentifier = publisher;
	titleIdentifier = title;
	checkDigit = computeCheckDigit(countryIdentifier, publisherIdentifier, titleIdentifier);
}

ISBN::ISBN(std::string country, std::string publisher, std::string title, std::string digit)
{
	countryIdentifier = country;
	publisherIdentifier = publisher;
	titleIdentifier = title;
	checkDigit = digit;
}

std::string ISBN::computeCheckDigit(std::string country, std::string publisher, std::string title)
{
	int digit = 0;
	int counter = 10;

	for (int i = 0; i < country.size(); i++)
	{
		digit = digit + counter * (country[i] - '0');
		counter--;
	}

	for (int i = 0; i < publisher.size(); i++)	
	{
		digit = digit + counter * (publisher[i] - '0');
		counter--;
	}

	for (int i = 0; i < title.size(); i++)
	{
		digit = digit + counter * (title[i] - '0');
		counter--;
	}


	int multiplier = digit / 11;

	digit = (multiplier + 1) * 11 - digit;

	digit = digit % 11;

	return std::to_string(digit);
}

void ISBN::printISBN()
{
	std::cout << countryIdentifier << "-" << publisherIdentifier << "-" << titleIdentifier << "-" << checkDigit << "\n";
}

const std::string ISBN::getCountryIdentidier()
{
	return countryIdentifier;
}

const std::string ISBN::getPublisherIdentifier()
{
	return publisherIdentifier;
}

const std::string ISBN::getTitleIdentifier()
{
	return titleIdentifier;
}

const std::string ISBN::getCheckDigit()
{
	return checkDigit;
}
