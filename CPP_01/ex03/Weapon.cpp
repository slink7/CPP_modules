
#include "Weapon.hpp"

Weapon::Weapon() {
	_type = "Default";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

const std::string& Weapon::get_type(void) {
	return (_type);
}

void Weapon::setType(std::string type) {
	_type = type;
}