#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& name);
	virtual ~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string&	getName() const;
	int					getHitPoints() const;
	int					getEnergy() const;
	int					getAttackDamage() const;
protected:
	std::string	name;
	int			hit_points;
	int			energy;
	int			attack_damage;
};

#endif