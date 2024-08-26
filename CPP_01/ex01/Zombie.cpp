#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie() {
	_name = "";
	std::cout << "Created Default\n";
}

Zombie::Zombie(std::string name) {
	_name = name;
	std::cout << "Created " << _name << "\n";
}

Zombie::~Zombie() {
	std::cout << "Destroyed \'" << _name << "'\n";
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}