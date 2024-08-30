#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public :
	Weapon();
	Weapon(std::string type);

	const std::string& getType(void);
	void setType(const std::string& type);
private :
	std::string _type;
};

#endif