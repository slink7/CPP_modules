#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Created Dog\n";
}

Dog::~Dog() {
	delete (brain);
	std::cout << "Destroyed Dog\n";
}

void	Dog::makeSound() const {
	std::cout << "Woof !\n";
}