#ifndef AMATERIA_HPP
#define AMATERIA_HPP

//Sujet
#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string	type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& cpy);
	virtual ~AMateria();

	AMateria&	operator=(const AMateria& cpy);

	std::string const& getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif