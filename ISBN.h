#pragma once
#include <string>

class ISBN
{
public:
	ISBN();
	ISBN(std::string, std::string, std::string);
	ISBN(std::string, std::string, std::string, std::string);
	std::string computeCheckDigit(std::string, std::string, std::string);
	void printISBN();
	const std::string getCountryIdentidier();
	const std::string getPublisherIdentifier();
	const std::string getTitleIdentifier();
	const std::string getCheckDigit();
	~ISBN();

private:
	std::string countryIdentifier;
	std::string publisherIdentifier;
	std::string titleIdentifier;
	std::string checkDigit;
};

