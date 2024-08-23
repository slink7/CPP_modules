
#include <iostream>

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
}
