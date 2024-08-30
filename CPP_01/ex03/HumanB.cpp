#include <iostream>
#include <string>

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = 0;
}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with " << _weapon->getType() << "\n";
}