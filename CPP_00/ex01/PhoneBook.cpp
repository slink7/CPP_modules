
#include <iostream>

#include "PhoneBook.hpp"
#include "Contact.hpp"

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

	for (int k = 0; k < 8; k++)
	{
		std::cout << k << " " << contacts[k].getField(FIRST_NAME) << "\n";
	}
}
