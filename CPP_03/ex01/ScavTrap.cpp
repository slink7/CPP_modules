#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :
	ClapTrap()
{
	name = "Johnattan";
	hit_points = 100;
	energy = 50;
	attack_damage = 20;
	std::cout << "Default ScavTrap has been created.\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) :
	ClapTrap()
{
	name = other.getHitPoints();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	std::cout << "ScavTrap " << name << " has been copied !\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	name = other.getHitPoints();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	return (*this);
}

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	hit_points = 100;
	energy = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " has been created !\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " has been destroyed !\n*sad noises*\n";
}

void ScavTrap::attack(const std::string &target) {
	if (hit_points <= 0) {
		std::cout << "ScavTrap " << name << " is dead !\n";
		return ;
	}
	if (energy-- <= 0) {
		std::cout << "ScavTrap " << name << " has not enough energy !\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage !\n";
}

void ScavTrap::guardGate() {
	if (hit_points > 0)
		std::cout << "ScavTrap " << name << " is entering gate guarding mode.\n";
}

