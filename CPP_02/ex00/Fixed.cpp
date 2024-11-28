#include <iostream>

#include "Fixed.hpp"

const int	Fixed::offset = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	bits = 0;
}

Fixed::Fixed(const Fixed& cpy) {
	std::cout << "Copy constructor called\n";
	*this = cpy;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

const Fixed&	Fixed::operator=(const Fixed& cpy) {
	std::cout << "Copy assignment operator called\n";
	bits = cpy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (bits);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	bits = raw;
}