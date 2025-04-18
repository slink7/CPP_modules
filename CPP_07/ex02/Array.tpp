#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstring>

template<class T>
void	print(T& value) {
	std::cout << value << "\n";
}

template<class T>
class Array {

public:
	Array() :
		_length(0),
		_array(0)
	{}

	Array(const Array& other) :
		_length(0),
		_array(0)
	{
		*this = other;
	}

	Array(unsigned int len) :
		_length(len),
		_array(new T[len]())
	{
		std::memset(_array, 0, sizeof(T) * len);
	}

	~Array() {
		if (_array)
			delete[] (_array);
	}

	Array&	operator=(const Array& other) {
		if (other.size() != size()) {
			_length = other.size();
			if (_array)
				delete[] (_array);
			_array = new T[size()]();
		}

		for (unsigned int k = 0; k < size(); k++) {
			(*this)[k] = other[k];
		}
		return (*this);
	}

	T&		operator[](unsigned int index) {
		if (index >= size())
			throw (std::out_of_range("index out of range"));
		return (_array[index]);
	}

	const T&		operator[](unsigned int index) const {
		if (index >= size())
			throw (std::out_of_range("index out of range"));
		return (_array[index]);
	}

	unsigned int	size(void) const {
		return (_length);
	}

	void			iter(void (*f)(T&)) {
		for (unsigned int k = 0; k < size(); ++k) {
			f((*this)[k]);
		}
	}

private:
	unsigned int	_length;
	T				*_array;
};

#endif