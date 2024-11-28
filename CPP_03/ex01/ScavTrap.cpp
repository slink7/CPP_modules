#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) {
	hit_points = 100;
	energy = 50;
	attack_damage = 20;
	this->name = name;
	std::cout << "A new ScavTrap has been created !\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "*Sad destroyed scavtrap sound*\n";
}

void ScavTrap::attack(const std::string &target) {
	if (hit_points <= 0) {
		std::cout << name << " is dead !\n";
		return ;
	}
	if (energy-- <= 0) {
		std::cout << name << " has not enough energy !\n";
		return ;
	}
	std::cout << "(ScavTrap)" << name << " attacks " << target << ", causing " << attack_damage << " points of damage !\n";

}

void ScavTrap::guardGate() {
	std::cout << "<" << name << "> Entering gate guarding mode.\n";
}
