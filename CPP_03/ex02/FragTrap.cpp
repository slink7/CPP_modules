#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) {
	hit_points = 100;
	energy = 100;
	attack_damage = 30;
	this->name = name;
	std::cout << "A new FragTrap has been created !\n";
}

FragTrap::~FragTrap() {
	std::cout << "*Sad destroyed fragtrap sound*\n";
}

void FragTrap::highFivesGuys() {
	std::cout << "<" << name << "> Who's up for a high five ??\n";
}
