#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
public:
	Span();
	Span(const Span& other);
	Span(unsigned int size);
	~Span();

	Span&	operator=(const Span& other);

	unsigned int	size() const;
	unsigned int	max_size() const;

	void			addNumber(int n);
	template<class T>
	void			addRange(T begin, T end);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

private:
	unsigned int		_size;
	unsigned int		_max_size;
	std::vector<int>	_content;
};

#endif

template <class T>
inline void Span::addRange(T begin, T end) {
	if (_size + end - begin > _max_size)
		throw (std::overflow_error("The Span has not enough place!"));
	for (T it = begin; it != end; ++it) {
		_content.push_back(*it);
	}
}