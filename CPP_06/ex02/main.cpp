#include <iostream>
#include <stdlib.h>

#include "classes.hpp"

Base	*generate(void) {
	std::cout << "Creating ";
	switch (rand() % 3) {
		case 0: std::cout << "A\n"; return (new A());
		case 1: std::cout << "B\n"; return (new B());
		case 2: std::cout << "C\n"; return (new C());
	}
	return (0);
}

void	identify(Base *p) {
	std::cout << "ptr identify: ";
	if (dynamic_cast<A*>(p)) {
		std::cout << "A";
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B";
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C";
	} else {
		std::cout << "Unknown";
	}
	std::cout << "\n";
}

void	identify(Base& p) {
	(void) p;
	std::cout << "ref identify: ";
	
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A\n";
	} catch(std::exception& e) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B\n";
	} catch(std::exception& e) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C\n";
	} catch(std::exception& e) {}
}

int main() {

	for (int k = 0; k < 10; k++) {
		Base *p = generate();

		identify(p);

		identify(*p);

		delete (p);

		std::cout << "\n";
	}

}