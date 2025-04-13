#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	_name("Joe"),
	_grade(120)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other.getName()),
	_grade(other.getGrade())
{
	checkGrade();
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name),
	_grade(grade)
{
	checkGrade();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	_grade = other.getGrade();
	return (*this);
}

const std::string &Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::upGrade() {\
	--_grade;
	checkGrade();
}

void Bureaucrat::downGrade() {
	++_grade;
	checkGrade();
}

void Bureaucrat::checkGrade() const {
	if (_grade < HIGHEST_GRADE)
		throw (GradeTooHighException());
	else if (_grade > LOWEST_GRADE)
		throw (GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureacrat) {
    os << bureacrat.getName() << ", bureaucrat grade " << bureacrat.getGrade();
    return os;
}