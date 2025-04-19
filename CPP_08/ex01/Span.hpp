#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstring>
#include <stdexcept>

class Span {
public:
	Span();
	Span(const Span& other);
	Span(unsigned int len);
	~Span();

	Span&		operator=(const Span& other);
	int&		operator[](unsigned int index);
	const int&	operator[](unsigned int index) const;

	unsigned int	size() const;
	unsigned int	getAddIndex() const;
	void			addNumber(int n);
	template<class T>
	void			addRange(T begin, T end);

	int				shortestSpan() const;
	int				longestSpan() const;


private:
	unsigned int	_length;
	unsigned int	_add_index;
	int				*_array;
};

#endif

template <class T>
inline void Span::addRange(T begin, T end) {
	while (begin != end) {
		addNumber(*begin);
		begin++;
	}
}
