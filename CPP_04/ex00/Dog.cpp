#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "Created Dog\n";
}

Dog::Dog(const Dog &other) :
	Animal(other)
{
	std::cout << "Copied Dog\n";
}

Dog::~Dog() {
	std::cout << "Destroyed Dog\n";
}

const Dog &Dog::operator=(const Dog &other) {
	type = other.getType();
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof ! *Wags tail*\n";
}