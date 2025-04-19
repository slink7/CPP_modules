#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
	Span span(10);

	span.addNumber(3);
	span.addNumber(7);
	span.addNumber(15);
	span.addNumber(51);
	span.addNumber(-4);

	std::cout << "Longest: " << span.longestSpan() << "\n";
	std::cout << "Shortest: " << span.shortestSpan() << "\n";

	std::vector<int> vec;
	vec.push_back(1000);
	vec.push_back(1001);
	vec.push_back(1002);
	vec.push_back(1003);

	span.addRange(vec.begin(), vec.end());

	std::cout << "Longest: " << span.longestSpan() << "\n";
	std::cout << "Shortest: " << span.shortestSpan() << "\n";
}