#include <iostream>
#include <vector>
#include <list>

#include "easyfind.tpp"

void	test_vector() {
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);

	std::vector<int>::const_iterator found = easyfind(vec, 2);

	if (found != vec.end())
		std::cout << "Found: " << *found << "\n";
	else
		std::cout << "Not found!\n";
}

void	test_list() {
	std::list<int> vec;

	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);

	std::list<int>::const_iterator found = easyfind(vec, 4);

	if (found != vec.end())
		std::cout << "Found: " << *found << "\n";
	else
		std::cout << "Not found!\n";
}


int	main() {
	test_vector();

	test_list();
}