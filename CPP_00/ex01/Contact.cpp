
#include <iostream>

#include "Contact.hpp"

std::string	Contact::getField(int index) {
	return (fields[index]);
}

void		Contact::readFromCin() {
	std::cout << "Enter first name : ";
	std::cin >> fields[FIRST_NAME];
	std::cout << "Enter last name : ";
	std::cin >> fields[LAST_NAME];
	std::cout << "Enter nickname : ";
	std::cin >> fields[NICKNAME];
	std::cout << "Enter phone number : ";
	std::cin >> fields[PHONE];
	std::cout << "Enter secret : ";
	std::cin >> fields[SECRET];
}

void Contact::print() {
	std::cout
		<< fields[FIRST_NAME] << " " << fields[LAST_NAME] << " (" << fields[NICKNAME] << ")\n"
		<< fields[PHONE] << "\n"
		<< fields[SECRET] << "\n";
}