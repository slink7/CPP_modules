#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	name = "John";
	hit_points = 10;
	energy = 10;
	attack_damage = 10;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	name = other.name;
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << name << " has been created !\n";
	this->name = name;
	hit_points = 10;
	energy = 10;
	attack_damage = 10;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " has been destroyed !\n";
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	name = other.name;
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	return (*this);
}


void		ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0) {
		std::cout << name << " is dead !\n";
		return ;
	}
	if (energy-- <= 0) {
		std::cout << name << " has not enough energy !\n";
		return ;
	}
	std::cout << name << " attacks " << target << ", causing " << attack_damage << " points of damage !\n";
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0) {
		std::cout << name << " is already dead !\n";
		return ;
	}
	hit_points -= amount;
	std::cout << name << " gets hit for " << amount << " points of damage !\n";
	if (hit_points <= 0) {
		std::cout << name << " died !\n";
		return ;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	hit_points += amount;
	std::cout << name << " gets healed for " << amount << " hits points !\n";
}


int			ClapTrap::getHitPoints() const {
	return (hit_points);
}

int			ClapTrap::getEnergy() const {
	return (energy);
}

int			ClapTrap::getAttackDamage() const {
	return (attack_damage);
}
