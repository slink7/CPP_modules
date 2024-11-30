#include "FragTrap.hpp"

FragTrap::FragTrap() :
	ClapTrap()
{
	name = "Jose";
	hit_points = 100;
	energy = 100;
	attack_damage = 30;
	std::cout << "Default FragTrap has been created.\n";
}

FragTrap::FragTrap(const std::string& name) :
	ClapTrap()
{
	this->name = name;
	hit_points = 100;
	energy = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " has been created !\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " has been destroyed\n";
}

void FragTrap::highFivesGuys() {
	if (hit_points > 0)
		std::cout << "<FragTrap " << name << "> Who's up for a high five ??\n";
}
