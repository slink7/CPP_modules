
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	void	addContact();
	void	printContact(int n);
	void	printContacts();
private:
	Contact contacts[8];
	int		index;
};

#endif