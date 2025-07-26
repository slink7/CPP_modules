class AForm;

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

#include "Bureaucrat.hpp"


class AForm {
public:

	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

	AForm();
	AForm(const AForm& other);
	AForm(const std::string& name, int sign_requirement, int exec_requirement, const std::string& target);
	virtual ~AForm();

	AForm&	operator=(const AForm& other);

	const std::string&	getName() const;
	bool				isSigned() const;
	int					getSignRequirement() const;
	int					getExecRequirement() const;
	const std::string&	getTarget() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const& executor) const = 0;

private:
	void				checkGrades();

	const std::string	_name;
	bool				_is_signed;
	const int			_sign_requirement;
	const int			_exec_requirement;
	const std::string	_target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif