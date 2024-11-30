#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap(const std::string& name);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& other);

	void	attack(const std::string& target);
	void	guardGate();
};

#endif