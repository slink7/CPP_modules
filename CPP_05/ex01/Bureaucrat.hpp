class Bureaucrat;

#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

#include "Form.hpp"

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
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

	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& other);

	const std::string&	getName() const;
	int					getGrade() const;

	void				upGrade();
	void				downGrade();
	void				signForm(Form& form);
private:
	void				checkGrade() const;

	const std::string	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureacrat);

#endif