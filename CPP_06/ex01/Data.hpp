#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data {
	int		integer;
	float	floating;
	char	character;
};

std::ostream& operator<<(std::ostream& os, const Data& data);

#endif