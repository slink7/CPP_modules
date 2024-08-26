#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
public :
	Weapon();
	Weapon(std::string type);

	const std::string& get_type(void);
	void setType(std::string);
private :
	std::string _type;
};

#endif