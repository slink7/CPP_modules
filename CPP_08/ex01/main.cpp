#include <iostream>
#include <vector>

#include "Span.hpp"

void	test_addRange_excepetion() {
	try {
		Span span(8);

		span.addNumber(3);
		span.addNumber(7);
		span.addNumber(15);
		span.addNumber(51);
		span.addNumber(-4);

		std::vector<int> vec;
		vec.push_back(1000);
		vec.push_back(1001);
		vec.push_back(1002);
		vec.push_back(1003);

		span.addRange(vec.begin(), vec.end());
	} catch (std::exception& e) {
		std::cout << "Exception caught! " << e.what() << "\n";
	}
	
}

void	test_too_small_span() {
	try {
		Span span(5);

		span.addNumber(0);

		span.shortestSpan();
	} catch (std::exception& e) {
		std::cout << "Exception caught! " << e.what() << "\n";
	}

	try {
		Span span(2);

		span.addNumber(0);
		span.addNumber(0);
		span.addNumber(0);

		span.shortestSpan();
	} catch (std::exception& e) {
		std::cout << "Exception caught! " << e.what() << "\n";
	}
}

void	test_10k() {
	const unsigned int size = 10000;
	Span span(size);
	std::cout << "Filling " << size << " elements...\n";
	for (unsigned int k = 0; k < size; k++) {
		span.addNumber(rand() % (10 * size));
	}

	std::cout << "Longest Span is:\n";
	std::cout << span.longestSpan() << "\n";

	std::cout << "Shortest Span is:\n";
	std::cout << span.shortestSpan() << "\n";
}

int main() {
	
	srand(time(0));

	test_10k();
	test_addRange_excepetion();
	test_too_small_span();

}