#ifndef ITER_TPP
#define ITER_TPP

template<class T>
void	print(T& value) {
	std::cout << value << "\n";
}

template<class T>
void	iter(T* array, const unsigned int array_length, void(*f)(T&)) {
	for (unsigned int k = 0; k < array_length; ++k)
		f(array[k]);
}

#endif
