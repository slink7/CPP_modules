#include "Span.hpp"

Span::Span() :
	_size(0),
	_max_size(0),
	_content(0)
{}

Span::Span(const Span& other) :
	_size(0),
	_max_size(0),
	_content(0)
{
	*this = other;
}

Span::Span(unsigned int size) :
	_size(0),
	_max_size(size),
	_content()
{
	_content.reserve(size);
}

Span::~Span()
{}

Span&	Span::operator=(const Span& other) {
	_size = other.size();
	_max_size = other.max_size();
	_content = other._content;
	return (*this);
}

unsigned int	Span::size() const {
	return (_size);
}

unsigned int	Span::max_size() const {
	return (_max_size);
}

void			Span::addNumber(int n) {
	if (_size >= _max_size)
		throw (std::overflow_error("The span if already full!"));
	_content.push_back(n);
	++_size;
}

unsigned int	Span::shortestSpan() {
	if (_size < 2)
		throw (std::range_error("Not enough elements in span!"));
	std::sort(_content.begin(), _content.end());
	unsigned int shortest = 0x0FFFFFFFF;
	for (unsigned int k = 0; k < _size - 1; k++) {
		unsigned int	distance = _content[k + 1] - _content[k];
		if (distance == 0)
			return (0);
		if (shortest > distance)
			shortest = distance;
	}
	return (shortest);
}

unsigned int	Span::longestSpan() {
	if (_size < 2)
		throw (std::range_error("Not enough elements in span!"));
	std::sort(_content.begin(), _content.end());
	return (_content.back() - _content.front());
}

