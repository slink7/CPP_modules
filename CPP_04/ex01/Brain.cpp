#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Created Brain\n";
}

Brain::Brain(const Brain &other) {
	*this = other;
}

Brain::~Brain() {
	std::cout << "Destroyed Brain\n";
}

const Brain &Brain::operator=(const Brain &other) {
	for (int k = 0; k < 100; k++)
		ideas[k] = other.ideas[k];
	return (*this);
}
