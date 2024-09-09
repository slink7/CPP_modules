#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int	Fixed::offset = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	bits = 0;
}

Fixed::Fixed(const Fixed& cpy) {
	std::cout << "Copy constructor called\n";
	bits = cpy.getRawBits();
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called\n";
	bits = n << offset;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called\n";
	bits =  (int)(roundf(n * (1 << offset)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed&	Fixed::operator=(const Fixed& cpy) {
	std::cout << "Copy assignment operator called\n";
	bits = cpy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

int		Fixed::getRawBits(void) const {
	return (bits);
}

void	Fixed::setRawBits(int const raw) {
	bits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)bits / (float)(1 << offset));
}

int		Fixed::toInt(void) const {
	return (bits >> offset);
}