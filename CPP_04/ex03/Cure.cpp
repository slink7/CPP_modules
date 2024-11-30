#include "Cure.hpp"

Cure::Cure() :
	AMateria("cure")
{}

Cure::Cure(const Cure& other) :
	AMateria(other.getType())
{}

Cure::~Cure()
{}

Cure &Cure::operator=(const Cure &cpy)
{
	type = cpy.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}