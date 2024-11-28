
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(const Fixed& cpy);
	~Fixed();
	const Fixed&	operator=(const Fixed& cpy);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					bits;
	const static int	offset;
};

#endif