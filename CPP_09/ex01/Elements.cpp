#include "Elements.hpp"

Integer::Integer() :
	value(0)
{}

Integer::Integer(const Integer& other) :
	value(other.getValue())
{}


Integer::Integer(int value) :
	value(value)
{}

Integer::~Integer()
{}

Integer& Integer::operator=(const Integer& other) {
	value = other.getValue();
	return (*this);
}

int	Integer::getValue() const {
	return (value);
}

Operator::Operator() :
	evaluation_function(0)
{}

Operator::Operator(const Operator& other) :
	evaluation_function(other.getEvaluationFunction())
{}

Integer	add(const Integer& a, const Integer& b) {
	return (Integer(a.getValue() + b.getValue()));
}

Integer	sub(const Integer& a, const Integer& b) {
	return (Integer(a.getValue() - b.getValue()));
}

Integer	mul(const Integer& a, const Integer& b) {
	return (Integer(a.getValue() * b.getValue()));
}

Integer	div(const Integer& a, const Integer& b) {
	return (Integer(a.getValue() / b.getValue()));
}

Integer	mod(const Integer& a, const Integer& b) {
	return (Integer(a.getValue() % b.getValue()));
}

Operator::Operator(char op) :
	evaluation_function(0)
{
	switch (op) {
		case '+': evaluation_function = add; break;
		case '-': evaluation_function = sub; break;
		case '*': evaluation_function = mul; break;
		case '/': evaluation_function = div; break;
		case '%': evaluation_function = mod; break;
		default: throw (std::invalid_argument("'' is not a valid operator."));
	}
}

Operator::~Operator()
{}

Operator& Operator::operator=(const Operator& other) {
	evaluation_function = other.getEvaluationFunction();
	return (*this);
}

Integer (*Operator::getEvaluationFunction() const)(const Integer &a, const Integer &b)
{
	return (evaluation_function);
}

IElement::~IElement()
{}
