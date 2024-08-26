#include <string>

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie temp = Zombie(name);
	temp.announce();
}

int main() {
	randomChump("Joe");

	Zombie *zombie = newZombie("Biden");
	zombie->announce();
	delete zombie;
}