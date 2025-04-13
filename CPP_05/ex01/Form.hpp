class Form;

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

#include "Bureaucrat.hpp"


class Form {
public:

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw() {
			return "The grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw() { 
			return "The grade is too low!";
		}
	};

	Form();
	Form(const Form& other);
	Form(const std::string& name, int sign_requirement, int exec_requirement);
	~Form();

	Form&	operator=(const Form& other);

	const std::string	getName() const;
	bool				isSigned() const;
	int					getSignRequirement() const;
	int					getExecRequirement() const;

	void				beSigned(const Bureaucrat& bureaucrat);

private:
	void				checkGrades();

	const std::string	_name;
	bool				_is_signed;
	const int			_sign_requirement;
	const int			_exec_requirement;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif