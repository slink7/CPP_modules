#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

void test(const std::string& bname, int bgrade, const std::string& fname, const std::string& target) {
	Bureaucrat	bureaucrat(bname, bgrade);
	Intern		intern;
	AForm		*form = intern.makeForm(fname, target);

	if (!form) {
		std::cout << "Wrong form name (robo, shrub, pardon)...\n";
		return ;
	}

	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	delete (form);
}


int main() {

	std::cout << "\n";
	test("Hidalgo", 50, "shrub", "Paris");
	std::cout << "\n";
	test("Bob", 1, "pardon", "Daniel");
	std::cout << "\n\n";
	test("Einstein", 25, "robo", "Dr. Emmett Brown");
	std::cout << "\n";

}