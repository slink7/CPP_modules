#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	const Brain&	operator=(const Brain& other);

private:
	std::string	ideas[100];
};

#endif