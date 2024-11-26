#include "Brain.hpp"

Brain::Brain() {}

Brain::Brain(const Brain &other) {
	*this = other;
}

Brain::~Brain() {}

const Brain &Brain::operator=(const Brain &other) {
	for (int k = 0; k < 100; k++)
		ideas[k] = other.ideas[k];
	return (*this);
}
