#include "DiamondTrap.hpp"

int main() {
	
	{
		DiamondTrap dt("GotoJail");

		dt.attack("Romain");
		dt.guardGate();
		dt.highFivesGuys();

		dt.attack("Daniel");
		dt.takeDamage(8);
		dt.beRepaired(20);
		dt.takeDamage(21);
		dt.highFivesGuys();
		dt.attack("Daniel");
		dt.takeDamage(1);
		dt.attack("Daniel");
		dt.whoAmI();
	}

	std::cout << "\n";

	{
		FragTrap *ct = new DiamondTrap("Magicarp");

		ct->attack("Louis");
		((DiamondTrap*)ct)->attack("Louis");
		((ClapTrap*)ct)->attack("Louis");

		delete (ct);
	}

}