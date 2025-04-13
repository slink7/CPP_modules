#include "Intern.hpp"

#define MAKEFORM(type, target) return new type (target);

typedef AForm* (*FormFactory)(const std::string&);

static AForm*	makeRobo(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

static AForm*	makeShrub(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}

static AForm*	makePres(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
	static struct { std::string key; FormFactory value; } map[] = {
		{ "robo", makeRobo },
		{ "shrub", makeShrub },
		{ "pardon", makePres }
	};

	for (int k = 0; k < 3; ++k)
		if (form == map[k].key)
			return (map[k].value(target));
	return (0);
}