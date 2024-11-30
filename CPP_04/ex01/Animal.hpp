#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal& cpy);
	Animal(const std::string& type);
	virtual ~Animal();

	Animal &operator=(const Animal& cpy);

	virtual void	makeSound();
	std::string		getType() const;
protected:
	std::string type;
};

#endif