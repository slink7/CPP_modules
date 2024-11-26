#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Created Dog\n";
}

Dog::~Dog() {
	std::cout << "Destroyed Dog\n";
}

void	Dog::makeSound() const {
	std::cout << "Woof !\n";
}