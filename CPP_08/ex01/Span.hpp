#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
public:
	Span();
	Span(const Span& other);
	Span(unsigned int len);
	~Span();

	Span&	operator=(const Span& other);

private:
	unsigned int	_length;
	int				*_array;
};

#endif