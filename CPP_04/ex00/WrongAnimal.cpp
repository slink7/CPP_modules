#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "WrongAnimal";
	std::cout << "Created WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
	type = cpy.getType();
	std::cout << "Copied WrongAnimal\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destroyed WrongAnimal\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "Copied WrongAnimal using =\n";
	type = other.getType();
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "*WrongAnimal sound*\n";
}

std::string WrongAnimal::getType() const
{
	return (type);
}
