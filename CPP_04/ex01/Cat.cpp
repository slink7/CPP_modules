#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat"),
	brain(new Brain()) 
{
	std::cout << "Created Cat\n";
}

Cat::Cat(const Cat &other) :
	Animal(other),
	brain(new Brain(*other.brain))
{
	std::cout << "Copied Cat\n";
}

Cat::~Cat() {
	delete (brain);
	std::cout << "Destroyed Cat\n";
}

const Cat &Cat::operator=(const Cat &other) {
	if (brain)
		delete (brain);
	type = other.getType();
	brain = new Brain(*other.brain);
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "*musique triste* Meow meow meow meow\n";
}