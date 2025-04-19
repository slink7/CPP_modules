#include <iostream>
#include <algorithm>

#include "MutantStack.tpp"

int main_enonce() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

void	test_de_moi_meme() {
	MutantStack<int> stack;

	stack.push(2);
	stack.push(13);
	stack.push(6);
	stack.push(7);
	stack.push(15);
	stack.push(-1);

	std::sort(stack.begin(), stack.end());

	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
		std::cout << *it << "\n";
	
}

int	main() {
	main_enonce();

	test_de_moi_meme();
}