#include <iostream>
#include <stack>
#include <stdexcept>

typedef int (*t_operator)(int, int);

int _add(int a, int b) {
	return (a + b);
}
int _sub(int a, int b) {
	return (a - b);
}
int _mul(int a, int b) {
	return (a * b);
}
int _div(int a, int b) {
	return (a / b);
}
int _mod(int a, int b) {
	return (a % b);
}

int	ReadStack(const std::string& calc) {
	std::stack<int> stack;
	struct {char key; t_operator op;} operator_map[] = {
		{'+', _add},
		{'-', _sub},
		{'*', _mul},
		{'/', _div},
		{'%', _mod},
		{0, 0}
	};

	bool shouldBeSpace = false;
	for (std::string::const_iterator it = calc.begin(); it != calc.end(); ++it) {
		if (shouldBeSpace && *it != ' ') {
			std::string e = "e";
			e[0] = *it;
			throw std::invalid_argument("Expected space instead of '" + e + "'\n");
		}
		if (*it == ' ') {
			shouldBeSpace = false;
			continue ;
		}
		if (std::string("0123456789").find(*it) != std::string::npos) {
			stack.push(*it - '0');
		}
		else if (std::string("+-*/%").find(*it) != std::string::npos) {
			for (int k = 0; operator_map[k].key; ++k) {
				if (operator_map[k].key == *it) {
					if (stack.size() < 2)
						throw std::invalid_argument("Syntax error");
					int a = stack.top(); stack.pop();
					int b = stack.top(); stack.pop();
					int n = operator_map[k].op(a, b);
					stack.push(n);
				}
			}
		} else {
			std::string e = "e";
			e[0] = *it;
			throw std::invalid_argument("Invalid char: '" + e + "'");
		}
		shouldBeSpace = true;
	}
	if (stack.size() != 1)
		throw std::invalid_argument("Syntax error");

	return (stack.top());
}

int main(int argc, char **argv) {
	
	if (argc != 2)
		return (1);
	try {
		int result = ReadStack(argv[1]);
		std::cout << argv[1] << " = " << result << "\n";
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
}

// 5 1 2 + 4 * + 3 -