#include <string>

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
	int count = 2;
	Zombie *horde = zombieHorde(count, "Glenn");

	for (int k = 0; k < count; k++)
		horde[k].announce();
	
	delete[] horde;
}