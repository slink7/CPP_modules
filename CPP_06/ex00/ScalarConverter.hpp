#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <stdlib.h>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& other);

public:
	static void	convert(const std::string& scalar);
};

#endif