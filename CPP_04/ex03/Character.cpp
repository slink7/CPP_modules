#include "Character.hpp"

Character::Character(const std::string &name):
	name(name),
	inventory({0})
{
}

Character::~Character()
{}

std::string const &Character::getName() const {
	return (name);
}

void Character::equip(AMateria *m) {
	for (int k = 0; k < INVENTORY_SIZE; k++) {
		if (inventory[k])
			continue;
		inventory[k] = m;
		return ;
	}
}
