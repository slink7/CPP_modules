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

FragTrap::FragTrap(const FragTrap &other) :
	ClapTrap()
{
	name = other.getHitPoints();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	std::cout << "FragTrap " << name << " has been copied !\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	name = other.getHitPoints();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	return (*this);
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
