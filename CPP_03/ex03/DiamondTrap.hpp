#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap(const std::string& name);
	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& other);

	void	attack(const std::string& other);
	void	whoAmI() const;
private:
	std::string	name;
};

#endif