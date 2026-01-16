
#include <iostream>
#include <string>

#include "iter.tpp"

void	double_it(int& value) {
	value *= 2;
}

void	shout_now(std::string& str) {
	for (unsigned long k = 0; k < str.length(); ++k) {
		if (str[k] <= 'z' && str[k] >= 'a')
			str[k] += 'A' - 'a';
	}
}

int main() {
	std::string strs[] = {
		"String A",
		"String B",
		"String C",
		"String D",
		"String E",
	};

	int			integers[] = {
		1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
	};

	const int	const_int[] = {
		32, 10, 90, 34
	};

	iter(integers, sizeof(integers) / sizeof(int), print);
	std::cout << "Doubling it and giving it to the next function call!\n";
	iter(integers, sizeof(integers) / sizeof(int), double_it);
	iter(integers, sizeof(integers) / sizeof(int), print);
	std::cout << "Now to strings, ...\n";
	iter(strs, sizeof(strs) / sizeof(std::string), print);
	std::cout << "I'm about to shout now !\n";
	iter(strs, sizeof(strs) / sizeof(std::string), shout_now);
	iter(strs, sizeof(strs) / sizeof(std::string), print);

	std::cout << "Now with const\n";
	iter(const_int, sizeof(const_int) / sizeof(int), print);
}
