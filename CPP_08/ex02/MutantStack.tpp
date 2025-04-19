#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::deque<T>::iterator iterator;

	iterator	begin() {
		return (std::stack<T>::c.begin());
	}

	iterator	end() {
		return (std::stack<T>::c.end());
	}
};

#endif