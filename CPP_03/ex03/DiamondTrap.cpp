#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("paolo_clap_name"), name("paolo")
{
	std::cout << "Default DiamondTrap has been created\n";
	this->FragTrap::hit_points = 100;
	this->ScavTrap::energy = 50;
	this->FragTrap::attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
{
	std::cout << "DiamondTrap " << other.name << " has been copied\n";
}

DiamondTrap::DiamondTrap(const std::string &name) 
	: ClapTrap(), name(name)
{
	std::cout << "DiamondTrap " << this->name << " has been created\n";
	this->ClapTrap::name = name + "_clap_name";
	this->FragTrap::hit_points = 100;
	this->ScavTrap::energy = 50;
	this->FragTrap::attack_damage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap has been destroyed.\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	name = other.getName();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	return (*this);
}

void DiamondTrap::attack(const std::string& other) {
	ScavTrap::attack(other);
}

void DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap is " << name << " (DiamondTrap), " << ClapTrap::name << " (ClapTrap)\n";
}
