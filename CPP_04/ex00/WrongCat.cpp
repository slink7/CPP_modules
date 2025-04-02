#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "Created WrongCat\n";
}

WrongCat::WrongCat(const WrongCat &cpy) {
	*this = cpy;
}

WrongCat::~WrongCat() {
	std::cout << "Destroyed WrongCat\n";
}

WrongCat &WrongCat::operator=(const WrongCat &cpy)
{
	type = cpy.type;
}

// void	WrongCat::makeSound() const {
// 	std::cout << "*musique triste* Meow meow meow meow\n";
// }