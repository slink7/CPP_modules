#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	
	Bureaucrat joe("Joe Biden", 20);

	Form independance("Declaration of independance", 1, 1);

	joe.signForm(independance);

	Form icecream("Icecream truck property", 143, 142);

	joe.signForm(icecream);

	try {
		Form rouleau("Rouleau des techniques ninja", 0, 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
}