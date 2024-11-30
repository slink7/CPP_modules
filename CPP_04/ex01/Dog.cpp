#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog"),
	brain(new Brain()) 
{
	std::cout << "Created Dog\n";
}

Dog::Dog(const Dog &other) :
	Animal(other),
	brain(new Brain(*other.brain))
{
	std::cout << "Copied Dog\n";
}

Dog::~Dog() {
	delete (brain);
	std::cout << "Destroyed Dog\n";
}

const Dog &Dog::operator=(const Dog &other) {
	if (brain)
		delete (brain);
	type = other.getType();
	brain = new Brain(*other.brain);
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Woof ! *Wags tail*\n";
}