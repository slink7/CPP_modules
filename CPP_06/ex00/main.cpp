
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "\e[1;31mNeeds at least one scalar argument (1, 4.6f, 9.6, c, etc)\n\e[0m";
		return (0);
	}
	for (int k = 1; k < argc; k++) {
		std::cout << "\e[1;36m\n\tConversion for \e[1;32m\"" << argv[k] << "\"\e[1;36m :\n\n\e[0m";
		ScalarConverter::convert(argv[k]);
		std::cout << "\n";
	}
}