#include <iostream>

#include "Array.tpp"

void	double_it(int& value) {
	value *= 2;
}

void	test_int() {
	Array<int> arr0(3);
	Array<int> arr1;
	Array<int> arr2(arr0);

	try {
		std::cout << "Accessing out of range:\n";
		arr0[100] = 4;
	} catch (std::exception& e) {
		std::cout << "An exception occured: " << e.what() << "\n";
	}

	std::cout << "Print arr1\n";
	arr1.iter(print);
	arr0[2] = 25;
	arr1 = arr0;
	
	
	
	
	arr0.iter(double_it);
	std::cout << "Print arr0\n";
	arr0.iter(print);
	
	std::cout << "Print arr1\n";
	arr1.iter(print);
}

void	shout_now(std::string& str) {
	for (unsigned long k = 0; k < str.length(); ++k) {
		if (str[k] <= 'z' && str[k] >= 'a')
			str[k] += 'A' - 'a';
	}
}

void	test_string() {
	Array<std::string> arr0(3);
	Array<std::string> arr1;
	Array<std::string> arr2(arr0);

	try {
		std::cout << "Accessing out of range:\n";
		arr0[100] = "Bababooey";
	} catch (std::exception& e) {
		std::cout << "An exception occured: " << e.what() << "\n";
	}

	std::cout << "Print arr1\n";
	arr1.iter(print);
	arr0[2] = "Ceci est une string";
	arr1 = arr0;
	
	
	
	
	arr0.iter(shout_now);
	std::cout << "Print arr0\n";
	arr0.iter(print);
	
	std::cout << "Print arr1\n";
	arr1.iter(print);
}

int	main() {

	test_int();

	test_string();

}