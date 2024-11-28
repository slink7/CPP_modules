
#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& cpy);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed	&operator=(const Fixed& other);
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed	&operator++(void);
	Fixed	operator++(int n);
	Fixed	&operator--(void);
	Fixed	operator--(int n);

	bool	operator>(Fixed const &other) const;
	bool	operator<(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;
	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
	
private:
	int					bits;
	const static int	offset;
};

std::ostream &operator<<(std::ostream &stream, const Fixed& fixed);

#endif