#include <iostream>
#include <stack>

#include <Elements.hpp>

int main() {
	Integer A(156);
	Integer B(15);
	Operator O('%');

	Integer C = O.getEvaluationFunction()(A, B);

	std::cout << "Result: " << C.getValue() << "\n";
}