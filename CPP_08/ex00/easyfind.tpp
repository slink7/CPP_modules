#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>

template<class T>
typename T::const_iterator	easyfind(T& container, int target) {
	return (std::find(container.begin(), container.end(), target));
}

template<class T>
typename T::const_iterator	easyfind2(T& container, int target) {
	int	index = 0;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it, ++index) {
		if (*it == target)
			return (it);
	}
	return (container.end());
}

#endif