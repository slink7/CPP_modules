#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery Creation", 145, 137, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	if (executor.getGrade() > getExecRequirement())
		throw (GradeTooLowException());

	std::string	file_name = getTarget() + "_Shrubbery";
	std::ofstream file(file_name.c_str());

	if (!file.is_open()) {
		std::cout << "File not openned\n";
		return ;
	}

	const std::string tree = ""\
		"      ________\n"\
		"  ___/   *    \\\n"\
		" /             \\\n"\
		"|  *    \\_/  *  |\n"\
		" \\__        ___/\n"\
		"   \\___*_____/\n"\
		"     |  |\n"\
		"      | |\n"\
		"      |  \\\n"\
		"      /   |\n"\
		"    /   | \\\n"
	;

	file << tree;

	file.close();
}
