
#include "ClapTrap.hpp"

int	main() {
	ClapTrap joe("Joe");

	joe.attack("Daniel");
	joe.takeDamage(8);
	joe.beRepaired(20);
	joe.takeDamage(21);
	joe.attack("Daniel");
	joe.takeDamage(1);
	joe.attack("Daniel");
}