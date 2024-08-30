#include <iostream>
#include <string>

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
}

void HumanA::attack() {
	std::cout << _name << " attacks with " << _weapon.getType() << "\n";
}