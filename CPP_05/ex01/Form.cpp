#include "Form.hpp"

Form::Form() :
	_name("Juandre"),
	_is_signed(false),
	_sign_requirement(100),
	_exec_requirement(100)
{
	checkGrades();
}

Form::Form(const Form &other) :
	_name(other.getName()),
	_is_signed(other.isSigned()),
	_sign_requirement(other.getSignRequirement()),
	_exec_requirement(other.getExecRequirement())
{
	checkGrades();
}

Form::Form(const std::string &name, int sign_requirement, int exec_requirement) :
	_name(name),
	_is_signed(false),
	_sign_requirement(sign_requirement),
	_exec_requirement(exec_requirement)
{
	checkGrades();
}

Form::~Form() {}

Form &Form::operator=(const Form &other) {
	_is_signed = other.isSigned();
	return (*this);
}

const std::string Form::getName() const {
	return (_name);
}

bool Form::isSigned() const {
	return (_is_signed);
}

int Form::getSignRequirement() const {
	return (_sign_requirement);
}

int Form::getExecRequirement() const {
	return (_exec_requirement);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _sign_requirement)
		throw (GradeTooLowException());
	_is_signed = true;
}

void Form::checkGrades() {
	if (_sign_requirement < HIGHEST_GRADE || _exec_requirement < HIGHEST_GRADE)
		throw (GradeTooHighException());
	if (_sign_requirement > LOWEST_GRADE || _exec_requirement > LOWEST_GRADE)
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "[" << (form.isSigned() ? "V" : "X") << "]" << form.getName();
    return os;
}