#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <stdexcept>
#include <string>

class IElement {
protected:
	virtual ~IElement();
};

class Integer : public IElement {
public:
	Integer();
	Integer(const Integer& other);
	Integer(int value);
	~Integer();

	Integer& operator=(const Integer& other);

	int	getValue() const;

private:
	int value;
};

class Operator : public IElement {
public:
	Operator();
	Operator(const Operator& other);
	Operator(char op);
	~Operator();

	Operator& operator=(const Operator& other);

	Integer	(*getEvaluationFunction() const)(const Integer& a, const Integer& b);

private:
	Integer	(*evaluation_function)(const Integer& a, const Integer& b);
};

#endif