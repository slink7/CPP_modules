#include "AForm.hpp"

AForm::AForm() :
	_name("Juandre"),
	_is_signed(false),
	_sign_requirement(100),
	_exec_requirement(100),
	_target("Yann")
{
	checkGrades();
}

AForm::AForm(const AForm &other) :
	_name(other.getName()),
	_is_signed(other.isSigned()),
	_sign_requirement(other.getSignRequirement()),
	_exec_requirement(other.getExecRequirement())
{
	checkGrades();
}

AForm::AForm(const std::string &name, int sign_requirement, int exec_requirement, const std::string& target) :
	_name(name),
	_is_signed(false),
	_sign_requirement(sign_requirement),
	_exec_requirement(exec_requirement),
	_target(target)
{
	checkGrades();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
	_is_signed = other.isSigned();
	return (*this);
}

const std::string& AForm::getName() const {
	return (_name);
}

bool AForm::isSigned() const {
	return (_is_signed);
}

int AForm::getSignRequirement() const {
	return (_sign_requirement);
}

int AForm::getExecRequirement() const {
	return (_exec_requirement);
}

const std::string& AForm::getTarget() const {
	return (_target);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign_requirement)
		throw (GradeTooLowException());
	_is_signed = true;
}

void AForm::checkGrades() {
	if (_sign_requirement < HIGHEST_GRADE || _exec_requirement < HIGHEST_GRADE)
		throw (GradeTooHighException());
	if (_sign_requirement > LOWEST_GRADE || _exec_requirement > LOWEST_GRADE)
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "[" << (form.isSigned() ? "V" : "X") << "]" << form.getName();
    return os;
}