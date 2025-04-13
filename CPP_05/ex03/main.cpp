#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"

int main() {

	Intern	someGuy;
	AForm	*form;

	form = someGuy.makeForm("robo", "Paul");

	if (!form)
		return (0);

	Bureaucrat	jhon("Lennon", 1);

	jhon.signForm(*form);
	jhon.executeForm(*form);
	
	std::cout << "A\n";
	delete (form); // SEGFAULT
	std::cout << "B\n";
	form = someGuy.makeForm("shrub", "Daniel");

	std::cout << "C\n";

	if (!form)
		return (0);

	jhon.signForm(*form);
	jhon.executeForm(*form);

	delete (form);
}