#ifndef ZOMBIE_HPP
#define ZOMBIE_PP

#include <string>

class Zombie {
public:
	void announce();
	Zombie(std::string name);
	~Zombie();
private:
	std::string _name;
};

#endif