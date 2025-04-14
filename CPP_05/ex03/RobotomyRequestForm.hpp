#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <stdlib.h>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const& executor) const;
};

#endif