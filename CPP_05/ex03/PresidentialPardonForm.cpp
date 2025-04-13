#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("Presidential Pardon", 25, 5, target)
{}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecRequirement())
		throw (GradeTooLowException());

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox";
}