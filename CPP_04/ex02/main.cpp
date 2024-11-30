#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {

	// Animal E;

	const int N = 4;

	Animal* zoo[N];
	for (int k = 0; k < N; k++) {
		if (k % 2)
			zoo[k] = new Cat();
		else
			zoo[k] = new Dog();
	}

	for (int k = 0; k < N; k++)
		zoo[k]->makeSound();
	
	for (int k = 0; k < N; k++)
		delete (zoo[k]);
}