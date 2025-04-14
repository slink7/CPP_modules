#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();

	void	execute(Bureaucrat const& executor) const;
};

#endif