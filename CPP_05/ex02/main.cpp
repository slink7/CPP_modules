#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubTest() {
	Bureaucrat anne("Hidalgo", 45);

	ShrubberyCreationForm shrub("Paris");

	anne.executeForm(shrub);
	
	anne.signForm(shrub);
	
	anne.executeForm(shrub);
}

void	robotonomoscotolopyTest() {
	Bureaucrat frank("Einstein", 20);

	RobotomyRequestForm robo("Emet Brown");

	frank.signForm(robo);

	frank.executeForm(robo);
}

void	pardonTest() {
	Bureaucrat macaron("Manu", 10);

	PresidentialPardonForm pardon("Rob");

	macaron.signForm(pardon);

	macaron.executeForm(pardon);
}

int main() {

	srand(time(0));

	shrubTest();

	robotonomoscotolopyTest();
	
	pardonTest();
}