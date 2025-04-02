#include "AMateria.hpp"

AMateria::AMateria() :
	type("forbidden")
{}

AMateria::AMateria(std::string const &type) : type(type)
{}

AMateria::AMateria(const AMateria &cpy) {
	*this = cpy;
}

AMateria::~AMateria()
{}

AMateria &AMateria::operator=(const AMateria &cpy)
{
	type = cpy.type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "* tries to do forbidden magic on " << target.getName() << " *\n";
}
