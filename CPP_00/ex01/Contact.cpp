
#include <iostream>

#include "Contact.hpp"

#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


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

void print_10(std::string str)
{
	int	stri = 0;
	for (int k = 0; k < 10; k++)
	{
		if ((10 - k) > str.length())
			std::cout << ' ';
		else if (k == 9 && str.length() > 10)
			std::cout << '.';
		else
			std::cout << str.at(stri++);
	}
}

void Contact::print_inarr(int display_index) {
	std::string	temp = SSTR(display_index);
	std::cout << "|";
	print_10(temp);
	std::cout << "|";
	print_10(fields[FIRST_NAME]);
	std::cout << "|";
	print_10(fields[LAST_NAME]);
	std::cout << "|";
	print_10(fields[NICKNAME]);
	std::cout << "|\n";
}

void Contact::print() {
	std::cout
		<< "Name: " << fields[FIRST_NAME] << " " << fields[LAST_NAME] << " (" << fields[NICKNAME] << ")\n"
		<< "Phone: " << fields[PHONE] << "\n"
		<< "Secret: " << fields[SECRET] << "\n";
}