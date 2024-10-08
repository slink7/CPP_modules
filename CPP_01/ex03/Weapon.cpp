#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon() {
	_type = "Default";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

const std::string& Weapon::getType(void) {
	return (this->_type);
}

void Weapon::setType(const std::string& type) {
	this->_type = type;
}