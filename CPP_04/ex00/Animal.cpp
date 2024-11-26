#include "Animal.hpp"

Animal::Animal() {
	type = "Animal";
	std::cout << "Created Animal\n";
}

Animal::Animal(const Animal &cpy) {
	type = cpy.getType();
	std::cout << "Copied Animal\n";
}

Animal::~Animal() {
	std::cout << "Destroyed Animal\n";
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copied Animal using =\n";
	type = other.getType();
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "*Animal sound*\n";
}

std::string Animal::getType() const
{
	return (type);
}
