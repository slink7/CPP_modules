#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal& cpy);
	Animal(const std::string& type);
	~Animal();

	Animal &operator=(const Animal& cpy);

	void		makeSound() const;
	std::string	getType() const;
protected:
	std::string type;
};

#endif