#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& name);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	const std::string&	getName() const;
	int					getHitPoints() const;
	int					getEnergy() const;
	int					getAttackDamage() const;
private:
	std::string	name;
	int			hit_points;
	int			energy;
	int			attack_damage;
};

#endif