#include "Span.hpp"

Span::Span() :
	_length(0),
	_add_index(0),
	_array(0)
{}

Span::Span(const Span &other) : 
	_length(0),
	_add_index(0),
	_array(0)
{
	*this = other;
}

Span::Span(unsigned int len) :
	_length(len),
	_add_index(0),
	_array(new int[len])
{
	std::memset(_array, 0, len * sizeof(int));
}

Span::~Span() {
	if (_array)
		delete[] (_array);
}

Span &Span::operator=(const Span &other) {
	if (other.size() != size()) {
		_length = other.size();
		_add_index = 0;
		if (_array)
			delete[] (_array);
		_array = new int[size()];
	}
	for (unsigned int k = 0; k < other.size(); k++)
		addNumber(other[k]);
	return (*this);
}

int &Span::operator[](unsigned int index) {
	if (index >= _add_index)
		throw (std::out_of_range("Index out of range"));
	return (_array[index]);
}

const int &Span::operator[](unsigned int index) const {
	if (index >= _add_index)
		throw (std::out_of_range("Index out of range"));
	return (_array[index]);
}

unsigned int Span::size() const {
	return (_length);
}

unsigned int Span::getAddIndex() const {
	return (_add_index);
}

void Span::addNumber(int n) {
	if (_add_index >= _length)
		throw (std::overflow_error("The Span container is full!"));
	_array[_add_index++] = n;
}

int Span::longestSpan() const {
	if (_add_index < 2)
		throw (std::range_error("Not enough elements"));

	int min = 0x7FFFFFFF;
	int max = -0x80000000;
	for (unsigned int k = 0; k < _add_index; ++k) {
		if (_array[k] > max)
			max = _array[k];
		if (_array[k] < min)
			min = _array[k];
	}

	if (min > max)
		throw (std::range_error("Magic has occured!"));

	return (max - min);
}

int	abs(int x) {
	return (x < 0 ? -x : x); 
}

int	Span::shortestSpan() const {
	if (_add_index < 2)
		throw (std::range_error("Not enough elements"));
	
	int	shortest = 0x7FFFFFFF;
	for (unsigned int k = 0; k < _add_index; ++k) {
		for (unsigned int l = 0; l < _add_index; ++l) {
			if (k == l)
				continue ;
			int	distance = abs(_array[k] - _array[l]);
			if (distance < shortest)
				shortest = distance;
		}
	}

	return (shortest);
}
