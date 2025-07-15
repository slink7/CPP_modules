


#include <iostream>

#include <list>
#include <deque>
#include <vector>
#include <cstdlib>

namespace ft {
	bool    is_int(const std::string& input) {
		return (
			input.find_first_not_of("-0123456789") == std::string::npos && (
				input.find_last_of('-') == std::string::npos ||
				input.find_last_of('-') == 0
			)
		);
	}
}

template <class T>
void fill(T& container, int argc, char **argv) {
	for (int k = 0; k < argc; ++k) {
		if (!ft::is_int(argv[k])) {
			throw std::invalid_argument("Invalid argument: \'" + std::string(argv[k]) + "\'");
		}
		container.push_back(std::atoi(argv[k]));
	}
}

// template <class T>
// void	push_back_range(T& out, T& in, uint begin, uint end) {
// 	// end = (end < in.size()) ? end : in.size();
// 	for (uint k = begin; k < end; k++)
// 		out.push_back(in.at(k));
// }

// template <class T>
// void	swap_range(T& c, int begin_a, int count_a, int begin_b, int count_b) {
	
// 	if ((begin_b > begin_a && begin_b < begin_a + count_a) || (begin_a > begin_b && begin_a < begin_b + count_b))
// 		throw (std::invalid_argument("swap_range: ranges overlaps"));
	
// 	if (begin_b < begin_a) {
// 		std::swap(begin_a, begin_b);
// 		std::swap(count_a, count_b);
// 	}
		
// 	T out;

// 	push_back_range(out, c, (0), (begin_a));
// 	push_back_range(out, c, (begin_b), (begin_b + count_b));
// 	push_back_range(out, c, (begin_a + count_a), (begin_b));
// 	push_back_range(out, c, (begin_a), (begin_a + count_a));
// 	push_back_range(out, c, (begin_b + count_b), c.size());

// 	c = out;
// }

template <class T>
void print_container(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// template <class T>
// void merge_insert_sort(T& container, uint i = 1) {
// 	if (i < 1)
// 		i = 1;
	
// 	uint element_count = container.size() / i;
// 	std::cout << "Elemc: " << element_count << " (" << i << ") \n";
// 	if (element_count < 2)
// 		return ;
	
// 	int next_i = 2 * i;
// 	// print_container(container);
// 	for (uint k = 0; k < element_count; k += 2) {
// 		uint index_a = i * (k + 1) - 1;
// 		uint index_b = i * (k + 2) - 1;
		
// 		if (index_a >= container.size() || index_b >= container.size())
// 			break ;

// 		if (container[index_a] > container[index_b])
// 			swap_range(container, k * i, i, (k + 1) * i, i);	
// 	}

// 	merge_insert_sort(container, next_i);

// 	for (uint k = 0; k + 1 < element_count; k += 2) {
// 		uint left = k * next_i;
// 		uint mid = left + i;
// 		uint right = left + next_i;

// 		if (mid >= container.size())
// 			break;
// 		if (right > container.size())
// 			right = container.size();

// 		// Merge the two sorted ranges [left, mid) and [mid, right)
// 		std::vector<typename T::value_type> merged;
// 		uint i1 = left, i2 = mid;
// 		while (i1 < mid && i2 < right) {
// 			if (container[i1] < container[i2])
// 				merged.push_back(container[i1++]);
// 			else
// 				merged.push_back(container[i2++]);
// 		}
// 		while (i1 < mid)
// 			merged.push_back(container[i1++]);
// 		while (i2 < right)
// 			merged.push_back(container[i2++]);

// 		// Copy merged back to container
// 		for (uint j = 0; j < merged.size(); ++j)
// 			container[left + j] = merged[j];
// 	}

// 	// typename T::iterator mid = container.begin();
	
// }

// static void FillJacobsthal(unsigned long* out, unsigned int n) {
// 	unsigned long a = 0ul, b = 1ul;

// 	if (n > 0)
// 		out[0] = a;
// 	// if (n > 1)
// 	// 	out[1] = b;
// 	if (n < 2)
// 		return ; 

// 	for (unsigned int k = 1; k < n; k++) {
// 		out[k] = 2 * a + b;
// 		a = b;
// 		b = out[k];
// 	}
// }

template <class T>
void JacobstalMerge(T& smaller, T& larger) {
	unsigned int jacobstal_numbers[] = { 0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531 };

	for (unsigned int k = 0; smaller.size() > 0 && (jacobstal_numbers[k] - k) < smaller.size(); k++) {
		typename T::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller[jacobstal_numbers[k] - k]);
		larger.insert(it, smaller[jacobstal_numbers[k] - k]);
		smaller.erase(smaller.begin() + jacobstal_numbers[k] - k);
	}

	for (unsigned int k = 0; k < smaller.size(); k++) {
		typename T::iterator it = std::lower_bound(larger.begin(), larger.end(), smaller[k]);
		larger.insert(it, smaller[k]);
	}
}

template <class T>
void FordJohnsonSort(T& container) {
	T larger;
	T smaller;

	if (container.size() < 2)
		return ;

	for (unsigned int k = 0; k < container.size() / 2; k++) {
		bool ordered = container[2 * k] < container[2 * k + 1];
		smaller.push_back(container[2 * k + 1 - ordered]);
		larger.push_back(container[2 * k + ordered]);
	}
	if (container.size() % 2)
		larger.push_back(container[container.size() - 1]);
	
	FordJohnsonSort(larger);
	JacobstalMerge(smaller, larger);

	// std::cout << "===============\n";
	// print_container(smaller);
	// print_container(larger);
	container = larger;
}


// static void jacobsthal(std::vector<int> &smaller, std::vector<int> &larger)
// {
//     std::vector<int>::iterator iterator;
//     std::vector<int> jacobsthal = generate(smaller.size());
//     std::vector<bool> isInserted(smaller.size(), false);

//     // use jacobsthal pour inserer
//     for (size_t i = 0; i < jacobsthal.size(); i++)
//     {
//         int index = jacobsthal[i];
//         std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[index]);
//         larger.insert(pos, smaller[index]);
//         isInserted[index] = true;
//     }
//     // insere le reste
//     for (size_t i = 0; i < smaller.size(); i++)
//     {
//         if(!isInserted[i])
//         {
//           iterator = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
//           larger.insert(iterator, smaller[i]);
//         }
//     }
// }

// static void fordJohnson(std::vector<int> &arg)
// {
//     std::vector<int> smaller;
//     std::vector<int> larger;
    
//     if (arg.size() < 2)
//     {
//         return;
//     }
//     for (size_t i = 0; i < arg.size() - 1; i += 2)
//     {
//         if (arg[i] < arg[i + 1])
//         {
//             smaller.push_back(arg[i]);
//             larger.push_back(arg[i + 1]);
//         }
//         else
//         {
//             smaller.push_back(arg[i + 1]);
//             larger.push_back(arg[i]);
//         }
//     }
//     if (arg.size() % 2 != 0)
//     {
//         larger.push_back(arg[arg.size() - 1]);
//     }
//     fordJohnson(larger);
//     jacobsthal(smaller, larger);
//     arg = larger;
// }

std::vector<int> generate(size_t n)
{
    std::vector<int> jacobsthal;
   
    if (n == 0)
        return jacobsthal;
    
    size_t j0 = 0;
    jacobsthal.push_back(j0);
    
    size_t j1 = 1;
    if (j1 < n && (jacobsthal.empty() || j1 != (size_t)jacobsthal.back()))
    {
        jacobsthal.push_back(j1);
    }

    size_t jn = j1 + 2 * j0;
    while (jn < n)
    {
        if (jacobsthal.empty() || jn != (size_t)jacobsthal.back())
        {
            jacobsthal.push_back(jn);
        }
        j0 = j1;
        j1 = jn;
        jn = j1 + 2 * j0;
    }
    return jacobsthal;
}

int main(int argc, char **argv) {

	std::vector<int> v;

	try {
		fill(v, argc - 1, argv + 1);
	} catch (std::exception& e) {
		std::cerr << "An exception occured: " << e.what() << std::endl;
	 	return (1);
	}

	std::cout << " A =========================\n";
	print_container(v);
	std::cout << " B =========================\n";
	
	FordJohnsonSort(v);
	std::cout << " C =========================\n";
	
	print_container(v);
	std::cout << " D =========================\n";

	// std::deque<int> l;
	// std::vector<int> v;

	// try {
	// 	fill(l, argc - 1, argv + 1);
	// 	fill(v, argc - 1, argv + 1);
	// } catch (const std::invalid_argument& e) {
	// 	std::cerr << "An exception occured: " << e.what() << std::endl;
	// 	return (1);
	// }

	// // print_container(l);
	// // swap_range(l, 1, 2, 4, 1);
	
	// std::cout << "Pre:\n";

	// print_container(l);

	// std::cout << "Post:\n";

	// merge_insert_sort(l);
	// print_container(l);
	// try {

	// } catch (std::exception& e) {
	// 	std::cout << "Excepetion: " << e.what() << "\n";
	// }
	// merge_insert_sort(v);
	// std::cout << "List: ";
	// print_container(l);
	// std::cout << std::endl;
	// std::cout << "Vector: ";
	// print_container(v);
	// std::cout << std::endl;

	// return (0);
}

/*
7 6 9 0 1 4 3 5 8 2 (1)
7|6  9|0  1|4  3|5  8|2
6|7  0|9  1|4  3|5  2|8

	6 7 0 9 1 4 3 5 2 8 (2)
	6 7|0 9  1 4|3 5  2 8|
	6 7|0 9  1 4|3 5  2 8|

		6 7 0 9 1 4 3 5 2 8 (4)
		6 7 0 9|1 4 3 5  2 8
		1 4 3 5|6 7 0 9  2 8

			1 4 3 5 6 7 0 9 2 8 (8)
			1 4 3 5 6 7 0 9|2 8
			<-
		
		
		


*/