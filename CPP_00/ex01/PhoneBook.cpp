
#include <iostream>

#include <limits>

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	index = 0;
}

void	PhoneBook::addContact() {
	contacts[index].readFromCin();
	index = (index + 1) % 8;
}

void	PhoneBook::printContact(int n)
{
	contacts[n].print();
}
void	PhoneBook::printContacts()
{
	std::cout << "/----------+----------+----------+----------\\\n";
	std::cout << "|        ID|First Name| Last Name|  Nickname|\n";
	std::cout << "+----------+----------+----------+----------+\n";
	for (int k = 0; k < 8; k++)
	{
		contacts[k].print_inarr(k);
	}
	std::cout << "\\----------+----------+----------+----------/\n";
	int index = -1;
	do {
		std::cout << "Index:";
		std::cin >> index;
		if (std::cin.fail() || index < 0 || index > 7)
		{
			std::cout << "Invalid Index\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			index = -1;
			continue ;
		}
	} while (index < 0 || index > 7);
	contacts[index].print();
}
