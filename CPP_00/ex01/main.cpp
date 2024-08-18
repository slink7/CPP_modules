
#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"



int	main() {
	PhoneBook	rep;
	std::string input;
	do {
		std::cin >> input;
		if (!input.compare("ADD"))
			rep.addContact();
		else if (!input.compare("SEARCH"))
			rep.printContacts();

	} while (input.compare("EXIT"));
}