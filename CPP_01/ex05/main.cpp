#include "Harl.hpp"

void	test(const Harl& harl, const std::string& level) {
	std::cout << "Testing with \"" << level << "\" : \n";
	harl.complain(level);
	std::cout << "\n";
}

int	main() {
	Harl harl;

	test(harl, "DEBUG");
	test(harl, "INFO");
	test(harl, "WARNING");
	test(harl, "ERROR");
	test(harl, "CRISIS");
}