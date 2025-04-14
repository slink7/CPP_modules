
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Needs a scalar argument (1, 4.6f, 9.6, c, etc)\n";
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}