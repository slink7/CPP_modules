#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter {
public:
	Character(const std::string& name);
	~Character();

	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
private:
	Character(const Character& cpy);
	Character&	operator=(const Character& cpy);

	std::string		name;
	AMateria		*inventory[INVENTORY_SIZE];
};

#endif