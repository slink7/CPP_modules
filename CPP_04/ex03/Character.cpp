#include "Character.hpp"

Character::Character(const std::string &name):
	name(name),
	inventory()
{
	for (int k = 0; k < INVENTORY_SIZE; k++)
		inventory[k] = 0;
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

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return ;
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return ;
	inventory[idx]->use(target);
}
