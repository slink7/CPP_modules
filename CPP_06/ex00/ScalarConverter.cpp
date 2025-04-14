#include "ScalarConverter.hpp"
#include <limits>

#define _NANF     (0.0f/0.0f)
#define _POS_INFF (1.0f/0.0f)
#define _NEG_INFF (-1.0f/0.0f)

#define _NAN      (0.0/0.0)
#define _POS_INF  (1.0/0.0)
#define _NEG_INF  (-1.0/0.0)

enum ScalarType {
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

const std::string&	getReadableType(ScalarType type) {
	static std::string array[] = {
		"UNKNOWN",
		"CHAR",
		"INT",
		"FLOAT",
		"DOUBLE"
	};

	if (type < 1 || type > 4)
		return (array[0]);
	else
		return (array[type]);
}

struct Scalar {
	ScalarType type;
	union {
		char c;
		int i;
		float f;
		double d;
	} value;
};

std::string StrTrim(const std::string &str, const std::string &set) {

	std::size_t begin = str.find_first_not_of(set);
	if (begin == std::string::npos)
		return (std::string(""));

	std::size_t end = str.find_last_not_of(set);
	if (end == std::string::npos)
		return (std::string(""));

	return (str.substr(begin, end - begin + 1));
}

namespace ft {

	bool	is_float(const std::string& input) {
		return (
			input == "+inff" || input == "-inff" || input == "nanf" || (
				input.find_first_not_of("-0123456789.f") == std::string::npos &&
				input.at(input.length() - 1) == 'f' && (
					input.find_last_of('-') == std::string::npos ||
					input.find_last_of('-') == 0
				)
			)
		);
	}

	bool	is_double(const std::string& input) {
		return (
			input == "+inf" || input == "-inf" || input == "nan" || (
				input.find_first_not_of("-0123456789.") == std::string::npos &&
				input.find('.') != std::string::npos && (
					input.find_last_of('-') == std::string::npos ||
					input.find_last_of('-') == 0 
				)
			)
		);
	}

	bool	is_int(const std::string& input) {
		return (
			input.find_first_not_of("-0123456789") == std::string::npos && (
				input.find_last_of('-') == std::string::npos ||
				input.find_last_of('-') == 0
			)
		);
	}

	bool	is_char(const std::string& input) {
		return (input.length() == 1);
	}
}

void	convertChar(const std::string& input) {
	char c = input[0];
	std::cout << "char: " << static_cast<char>(c) << ".\n";
	std::cout << "int: " << static_cast<int>(c) << ".\n";
	std::cout << "float: " << static_cast<float>(c) << "f.\n";
	std::cout << "double: " << static_cast<double>(c) << ".\n";
}

void	convertInt(const std::string& input) {
	int i = atoi(input.c_str());

	if (i < 0 || i > 127)
		std::cout << "char: impossible!\n";
	else if (!isprint(i))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << static_cast<char>(i) << ".\n";
	std::cout << "int: " << static_cast<int>(i) << ".\n";
	std::cout << "float: " << static_cast<float>(i) << "f.\n";
	std::cout << "double: " << static_cast<double>(i) << ".\n";
}

void	convertFloat(const std::string& input) {
	float	f = atof(input.c_str());
	char	c = static_cast<char>(f);

	if (c < 0 || c > 127 || f == nanf(""))
		std::cout << "char: impossible!\n";
	else if (!isprint(c)) 
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << c << "\n";
	if (f > (float)0x7FFFFFFF || f < -(float)0x80000000 || f != f)
		std::cout << "int: impossible!\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";
	std::cout << "float: " << static_cast<float>(f) << "f.\n";
	std::cout << "double: " << static_cast<double>(f) << ".\n";
}

void	convertDouble(const std::string& input) {
	float	d = atof(input.c_str());
	char	c = static_cast<char>(d);

	if (c < 0 || c > 127 || d == nan(""))
		std::cout << "char: impossible!\n";
	else if (!isprint(c)) 
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << c << "\n";
	if (d > (double)0x7FFFFFFF || d < -(double)0x80000000 || d != d)
		std::cout << "int: impossible!\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
	std::cout << "float: " << static_cast<float>(d) << "f.\n";
	std::cout << "double: " << static_cast<double>(d) << ".\n";
}


void ScalarConverter::convert(const std::string &scalar) {

	std::string clear_input = StrTrim(scalar, " \t");
	if (clear_input.size() < 1) {
		std::cout << "Invalid input.\n";
		return ;
	}

	typedef	bool (*type_predicat)(const std::string&);
	typedef	void (*converter)(const std::string&);

	struct map_entry {
		type_predicat	predicat;
		converter		converter;
	};

	struct map_entry predicat_map[] = {
		{ft::is_char, convertChar},
		{ft::is_int, convertInt},
		{ft::is_float, convertFloat},
		{ft::is_double, convertDouble},
	};

	for (int k = 0; k < 4; ++k) {
		if (predicat_map[k].predicat(clear_input))
			return predicat_map[k].converter(clear_input);
	}

	std::cout << "Unknown input type...\n";
}