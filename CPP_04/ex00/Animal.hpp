#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const Animal& cpy);
	~Animal();

	Animal &operator=(const Animal&);

	void		makeSound() const;
	std::string	getType() const;
protected:
	std::string type;
};

#endif