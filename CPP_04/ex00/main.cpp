#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "\nTESTS A =================\n\n";
	{
		Animal A;

		A.makeSound();
		
		Cat B;
		Dog C;

		Cat D = B;

		C.makeSound();
		D.makeSound();
	}
	std::cout << "\nTESTS B =================\n\n";
	{
		WrongAnimal A;

		A.makeSound();

		WrongCat B;

		B.makeSound();
	}
}