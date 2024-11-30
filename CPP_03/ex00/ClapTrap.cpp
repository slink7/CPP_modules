#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("John"),
	hit_points(10),
	energy(10),
	attack_damage(10)
{
	std::cout << "Default ClapTrap created.\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	name(other.getName()),
	hit_points(other.getHitPoints()),
	energy(other.getEnergy()),
	attack_damage(other.getAttackDamage())
{
	std::cout << "ClapTrap " << name << " has been copied !\n";
}

ClapTrap::ClapTrap(const std::string& name) :
	name(name),
	hit_points(10),
	energy(10),
	attack_damage(10)
{
	std::cout << "ClapTrap " << name << " has been created !\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " has been destroyed !\n";
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	name = other.getName();
	hit_points = other.getHitPoints();
	energy = other.getEnergy();
	attack_damage = other.getAttackDamage();
	return (*this);
}


void		ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " can't attack because it is dead !\n";
		return ;
	}
	if (energy-- <= 0) {
		std::cout << "ClapTrap " << name << " has not enough energy to attack !\n";
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage !\n";
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " is already dead !\n";
		return ;
	}
	hit_points -= amount;
	std::cout << "ClapTrap " << name << " gets hit for " << amount << " points of damage !\n";
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " died !\n";
		return ;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	hit_points += amount;
	std::cout << "ClapTrap " << name << " gets healed for " << amount << " hits points !\n";
}


const std::string&	ClapTrap::getName() const {
	return (name);
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
