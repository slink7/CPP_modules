
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

	Fixed&			operator=(const Fixed& cpy);
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;
	
private:
	int					bits;
	const static int	offset;
};

std::ostream &operator<<(std::ostream &stream, const Fixed& fixed);

#endif