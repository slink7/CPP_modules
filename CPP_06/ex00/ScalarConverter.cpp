#include "ScalarConverter.hpp"

#define INT_MAXF 2147483647.0f
#define INT_MINF -2147483648.0f

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void) other;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return (*this);
}

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
				) &&
				input.find_first_of('.') == input.find_last_of('.')
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
				) &&
				input.find_first_of('.') == input.find_last_of('.')
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

	std::string	itos(int k) {
		std::stringstream stream;
		stream << k;
		return (stream.str());
	}
}

void	convertChar(const std::string& input) {
	char c = input[0];
	std::cout << "\e[0;36mchar: \e[0;32m'" << static_cast<char>(c) << "'\n";
	std::cout << "\e[0;36mint: \e[0;32m" << static_cast<int>(c) << "\n";
	std::cout << "\e[0;36mfloat: \e[0;32m" << static_cast<float>(c) << "f\n";
	std::cout << "\e[0;36mdouble: \e[0;32m" << static_cast<double>(c) << "\n";
}

void	convertInt(const std::string& input) {
	double	f = atof(input.c_str());
	int		i = atoi(input.c_str());

	if (i < 0 || i > 127)
		std::cout << "\e[0;36mchar: \e[1;31mimpossible!\n";
	else if (!isprint(i))
		std::cout << "\e[0;36mchar: \e[1;31mNot displayable\n";
	else
		std::cout << "\e[0;36mchar: \e[0;32m'" << static_cast<char>(i) << "'\n";
	if (input != ft::itos(i))
		std::cout << "\e[0;36mint: \e[1;31mimpossible!\n";
	else 
		std::cout << "\e[0;36mint: \e[0;32m" << static_cast<int>(i) << "\n";
	std::cout << "\e[0;36mfloat: \e[0;32m" << static_cast<float>(f) << "f\n";
	std::cout << "\e[0;36mdouble: \e[0;32m" << static_cast<double>(f) << "\n";
}

void	convertFloat(const std::string& input) {
	double	f = atof(input.c_str());
	char	c = static_cast<char>(f);

	if (c < 0 || c > 127 || f == nanf(""))
		std::cout << "\e[0;36mchar: \e[1;31mimpossible!\n";
	else if (!isprint(c)) 
		std::cout << "\e[0;36mchar: \e[1;31mNot displayable\n";
	else
		std::cout << "\e[0;36mchar: \e[0;32m'" << c << "'\n";
	if (f > INT_MAXF || f < INT_MINF || f != f)
		std::cout << "\e[0;36mint: \e[1;31mimpossible!\n";
	else
		std::cout << "\e[0;36mint: \e[0;32m" << static_cast<int>(f) << "\n";
	std::cout << "\e[0;36mfloat: \e[0;32m" << static_cast<float>(f) << "f\n";
	std::cout << "\e[0;36mdouble: \e[0;32m" << static_cast<double>(f) << "\n";
}

void	convertDouble(const std::string& input) {
	double	d = atof(input.c_str());
	char	c = static_cast<char>(d);

	if (c < 0 || c > 127 || d == nan(""))
		std::cout << "\e[0;36mchar: \e[1;31mimpossible!\n";
	else if (!isprint(c)) 
		std::cout << "\e[0;36mchar: \e[1;31mNot displayable\n";
	else
		std::cout << "\e[0;36mchar: \e[0;32m'" << c << "'\n";
	if (d > INT_MAXF || d < INT_MINF || d != d)
		std::cout << "\e[0;36mint: \e[1;31mimpossible!\n";
	else
		std::cout << "\e[0;36mint: \e[0;32m" << static_cast<int>(d) << "\n";
	std::cout << "\e[0;36mfloat: \e[0;32m" << static_cast<float>(d) << "f\n";
	std::cout << "\e[0;36mdouble: \e[0;32m" << static_cast<double>(d) << "\n";
}


void ScalarConverter::convert(const std::string &scalar) {

	std::string clear_input = StrTrim(scalar, " \t");
	if (clear_input.size() < 1) {
		std::cout << "\e[1;31mInvalid input\n";
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
		{ft::is_double, convertDouble}
	};

	for (int k = 0; k < 4; ++k) {
		if (predicat_map[k].predicat(clear_input))
			return predicat_map[k].converter(clear_input);
	}

	std::cout << "\e[1;31mUnknown input type..\n";
}