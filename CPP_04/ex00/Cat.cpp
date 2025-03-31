#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	std::cout << "Created Cat\n";
}

Cat::Cat(const Cat &other) :
	Animal(other)
{
	std::cout << "Copied Cat\n";
}

Cat::~Cat() {
	std::cout << "Destroyed Cat\n";
}

const Cat &Cat::operator=(const Cat &other) {
	type = other.getType();
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "*musique triste* Meow meow meow meow\n";
}