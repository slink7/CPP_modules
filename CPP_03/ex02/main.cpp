
#include "FragTrap.hpp"

int	main() {
	FragTrap joe("Joe");

	joe.attack("Daniel");
	joe.takeDamage(8);
	joe.beRepaired(20);
	joe.takeDamage(21);
	joe.highFivesGuys();
	joe.attack("Daniel");
	joe.takeDamage(1);
	joe.attack("Daniel");
}