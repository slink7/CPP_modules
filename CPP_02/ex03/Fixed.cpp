#include <iostream>
#include <cmath>

#include "Fixed.hpp"

const int	Fixed::offset = 8;

Fixed::Fixed() {
	bits = 0;
}

Fixed::Fixed(const Fixed& cpy) {
	bits = cpy.getRawBits();
}

Fixed::Fixed(const int n) {
	bits = n << offset;
}

Fixed::Fixed(const float n) {
	bits =  (int)(roundf(n * (1 << offset)));
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(const Fixed& cpy) {
	bits = cpy.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	out;

	out.setRawBits(bits + other.getRawBits());
	return (out);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	out;

	out.setRawBits(bits - other.getRawBits());
	return (out);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	out;

	out.setRawBits((bits * other.getRawBits()) >> offset);
	return (out);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed	out;

	out.setRawBits((bits << offset) / other.getRawBits());
	return (out);
}

Fixed	&Fixed::operator++(void) {
	bits++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	out(*this);

	operator++();
	return (out);
}

Fixed	&Fixed::operator--(void) {
	bits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	out(*this);

	operator--();
	return (out);
}

bool	Fixed::operator>(Fixed const &other) const {
	return (bits > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const {
	return (bits < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const {
	return (bits >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const {
	return (bits <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const &other) const {
	return (bits == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const {
	return (bits != other.getRawBits());
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

int		Fixed::sign(void) const {
	float	k = toFloat();

	return ((k > 0.0f) - (k < 0.0f));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}
