#include "Ice.hpp"

Ice::Ice() :
	AMateria("ice")
{}

Ice::Ice(const Ice &cpy) :
	AMateria(cpy.getType())
{}

Ice::~Ice()
{}

Ice &Ice::operator=(const Ice &cpy)
{
	type = cpy.getType();
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}