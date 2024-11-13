#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	void announce();
	Zombie(std::string name);
	Zombie();
	~Zombie();
private:
	std::string _name;
};

#endif