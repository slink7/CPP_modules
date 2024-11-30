#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& cpy);
	~Ice();

	Ice&	operator=(const Ice& cpy);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif