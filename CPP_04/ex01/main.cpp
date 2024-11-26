#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {

	std::cout << "\nTESTS A =================\n\n";
	{
		Cat B;
		Cat D = B;

		B.makeSound();
		D.makeSound();
	}
}