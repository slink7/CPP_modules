#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("Robotomy Request", 72, 45, target)
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecRequirement())
		throw (GradeTooLowException());

	std::cout << " * Drilling noises * \n";

	if (rand() % 2)
		std::cout << getTarget() << " has been Robotonomotized - Over\n";
	else
		std::cout << "The Robotonomotization has failed ! Back up !\n";
}