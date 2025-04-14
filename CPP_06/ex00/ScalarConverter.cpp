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

namespace ft
{
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

	float	stof(const std::string& input) {
		if (input == "nanf")
			return (_NANF);
		if (input == "+inff")
			return (_POS_INFF);
		if (input == "-inff")
			return (_NEG_INFF);
		std::istringstream	stream(input);
		float				out;
		stream >> out;
		std::cout << "value:" << out << "\n"; 
		return (out);
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

	double	stod(const std::string& input) {
		if (input == "nan")
			return (_NAN);
		if (input == "+inf")
			return (_POS_INF);
		if (input == "-inf")
			return (_NEG_INF);
		std::istringstream	stream(input);
		double				out;
		stream >> out;
		std::cout << "value:" << out << "\n"; 
		return (out);
	}

	bool	is_int(const std::string& input) {
		return (
			input.find_first_not_of("-0123456789") == std::string::npos && (
				input.find_last_of('-') == std::string::npos ||
				input.find_last_of('-') == 0
			)
		);
	}

	int	stoi(const std::string& input) {
		std::istringstream	stream(input);
		int					out;
		stream >> out;
		std::cout << "value:" << out << "\n"; 
		return (out);
	}
}

std::string	wrappedChar(char c) {
	if (!isprint(c)) {
		return ("Not displayable");
	}
	std::string out = "\000";
	out[0] = c;
	return (out);
}


void ScalarConverter::convert(const std::string &scalar) {

	std::string clear_input = StrTrim(scalar, " \t");
	if (clear_input.size() < 1) {
		std::cout << "Invalid input.\n";
		return ;
	}

	Scalar base;

	if (ft::is_float(clear_input)) {
		base.type = FLOAT;
		base.value.f = ft::stof(clear_input);	
	} else if (ft::is_double(clear_input)) {
		base.type = DOUBLE;
		base.value.d = ft::stod(clear_input);
	} else if (ft::is_int(clear_input)) {
		base.type = INT;
		base.value.i = ft::stoi(clear_input);
	} else if (clear_input.size() == 1) {
		base.type = CHAR;
		base.value.c = clear_input.at(0);
	}

	std::cout << "Input type: [" << base.type << "]." << getReadableType(base.type) << ".\n";

	switch (base.type) {
		case CHAR:
			std::cout << "char: " << wrappedChar(static_cast<char>(base.value.c)) << ".\n";
			std::cout << "int: " << static_cast<int>(base.value.c) << ".\n";
			std::cout << "float: " << static_cast<float>(base.value.c) << "f.\n";
			std::cout << "double: " << static_cast<double>(base.value.c) << ".\n";
			break;
		case INT:
			std::cout << "char: " << wrappedChar(static_cast<char>(base.value.i)) << ".\n";
			std::cout << "int: " << static_cast<int>(base.value.i) << ".\n";
			std::cout << "float: " << static_cast<float>(base.value.i) << "f.\n";
			std::cout << "double: " << static_cast<double>(base.value.i) << ".\n";
			break;
		case FLOAT:
			if (base.value.f == _POS_INFF || base.value.f == _NEG_INFF || base.value.f == _NANF) {
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
			} else {
				std::cout << "char: " << wrappedChar(static_cast<char>(base.value.f)) << ".\n";
				std::cout << "int: " << static_cast<int>(base.value.f) << ".\n";
			}
			std::cout << "float: " << static_cast<float>(base.value.f) << "f.\n";
			std::cout << "double: " << static_cast<double>(base.value.f) << ".\n";
			break;
		case DOUBLE:
			if (base.value.d == _POS_INF || base.value.d == _NEG_INF || base.value.d == _NAN) {
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
			} else {
				std::cout << "char: " << wrappedChar(static_cast<char>(base.value.d)) << ".\n";
				std::cout << "int: " << static_cast<int>(base.value.d) << ".\n";
			}
			std::cout << "float: " << static_cast<float>(base.value.d) << "f.\n";
			std::cout << "double: " << static_cast<double>(base.value.d) << ".\n";
			break;
		default:
			std::cout << "Unknown type bruh\n";
	}
}