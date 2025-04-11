
#include <iostream>

#include "Bureaucrat.hpp"

void testConstructors() {
	for (int k = 0; k < 7; k++) {

		int grade = k * 30;
		std::cout << "Creating Bureaucrat with grade : " << grade << " : ";

		try {
			Bureaucrat bureaucraft("Joe", grade);
			std::cout << "Success!";
		} catch (std::exception& e) {
			std::cout << e.what();
		}
		std::cout << "\n";
	}
}

void testUpDownGrading() {
	Bureaucrat fromTopToBottom("Alex", 1);
	Bureaucrat fromBottomToTop("Steve", 150);

	for (int k = 0; k < 151; k++) {
		try {
			fromBottomToTop.upGrade();
		} catch (std::exception& e) {
			std::cout << fromBottomToTop << " : " << e.what() << "\n";
		}

		try {
			fromTopToBottom.downGrade();
		} catch (std::exception& e) {
			std::cout << fromTopToBottom << " : " << e.what() << "\n";
		}
	}
}

int main() {


	testConstructors();
	
	testUpDownGrading();



	return (0);
}