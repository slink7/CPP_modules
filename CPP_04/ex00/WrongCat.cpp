#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "Created WrongCat\n";
}

WrongCat::~WrongCat() {
	std::cout << "Destroyed WrongCat\n";
}

// void	WrongCat::makeSound() const {
// 	std::cout << "*musique triste* Meow meow meow meow\n";
// }