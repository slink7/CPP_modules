#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Created cat\n";
}

Cat::~Cat() {
	delete (brain);
	std::cout << "Destroyed cat\n";
}

Cat::Cat(const Cat &other) {
	*this = other;
}

const Cat &Cat::operator=(const Cat &other) {
	if (brain)
		delete (brain);
	brain = new Brain(*other.brain);
	type = other.type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "*musique triste* Meow meow meow meow\n";
}