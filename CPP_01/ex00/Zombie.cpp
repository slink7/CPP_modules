#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie() {
	std::cout << "Destroyed \'" << _name << "'\n";
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}