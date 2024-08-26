#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name ) {
	Zombie *out = new Zombie[N];

	for (int k = 0; k < N; k++)
		out[k] = Zombie(name);
	return (out);
}