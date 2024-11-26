#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& cpy);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal&);

	void		makeSound() const;
	std::string	getType() const;
protected:
	std::string type;
};

#endif