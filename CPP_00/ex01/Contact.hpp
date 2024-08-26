
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

#define FIRST_NAME	0
#define LAST_NAME	1
#define NICKNAME	2
#define PHONE		3
#define SECRET		4

class Contact 
{
public:
	std::string	getField(int index);
	std::string superCin(std::string prompt);
	void		readFromCin();
	void		print_inarr(int display_index);
	void		print();
private:
	std::string fields[5];
};

#endif