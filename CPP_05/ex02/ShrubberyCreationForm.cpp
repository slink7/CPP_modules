#include "ShrubberyCreationForm.hpp"

#define MAX_DEPTH 16
int rec[MAX_DEPTH];

class BST {
public:
	int	value;
	BST *left_child;
	BST	*right_child;

	BST(int value = 0) :
		value(value),
		left_child(0),
		right_child(0)
	{}

	~BST() {
		delete left_child;
		delete right_child;
	}

	void pushBack(int value) {
		BST	**dst = (this->value > value) ? &left_child : &right_child;
		if (!*dst)
			*dst = new BST(value);
		else
			(*dst)->pushBack(value);
	}

	void inOrderPrint() {
		if (left_child)
			left_child->inOrderPrint();
		std::cout << value << " ";
		if (right_child)
			right_child->inOrderPrint();
	}

	void	preOrderPrint() {
		std::cout << value << " ";
		if (left_child)
			left_child->preOrderPrint();
		if (right_child)
			right_child->preOrderPrint();
	}
	
	void	printHierarchy(std::ostream& out = std::cout, int depth = 0, bool isLeft = true) {
		for (int k = 0; k < depth; ++k) {
			if (k == depth - 1)
				out << ((isLeft) ? '+' : '\\') << "--";
			else
				out <<  (rec[k] ? '|' : ' ') << "  ";
		}
		out << value << "\n";
		rec[depth] = 1;
		if (left_child)
			left_child->printHierarchy(out, depth + 1, true);
		rec[depth] = 0;
		if (right_child)
			right_child->printHierarchy(out, depth + 1, false);
	}

	void pushBack(int count, int min, int max) {
		for (int k = 0; k < count; ++k)
			pushBack(min + rand() % (max - min));
	}
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("Shrubbery Creation", 145, 137, target)
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

	if (executor.getGrade() > getExecRequirement())
		throw (GradeTooLowException());

	std::string	file_name = getTarget() + "_Shrubbery";
	std::ofstream file(file_name.c_str());

	if (!file.is_open()) {
		std::cout << "File not openned\n";
		return ;
	}

	BST tree(10);

	tree.pushBack(10, 0, 20);

	tree.printHierarchy(file);

	file.close();
}
