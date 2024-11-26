#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Created cat\n";
}

Cat::~Cat() {
	std::cout << "Destroyed cat\n";
}

void	Cat::makeSound() const {
	std::cout << "*musique triste* Meow meow meow meow\n";
}