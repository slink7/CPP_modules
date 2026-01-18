


#include <iostream>

#include <list>
#include <deque>
#include <vector>
#include <cstdlib>


namespace ft {
	bool    IsInt(const std::string& input) {
		return (
			input.find_first_not_of("-0123456789") == std::string::npos && (
				input.find_last_of('-') == std::string::npos ||
				input.find_last_of('-') == 0
			)
		);
	}
}

template <class T>
void Fill(T& container, int argc, char **argv) {
	for (int k = 0; k < argc; ++k) {
		if (!ft::IsInt(argv[k])) {
			throw std::invalid_argument("Invalid argument: \'" + std::string(argv[k]) + "\'");
		}
		container.push_back(std::atoi(argv[k]));
	}
}

template <class T>
void PrintContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

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
	if (container.size() < 2)
		return ;

	T larger;
	T smaller;

	for (unsigned int k = 0; k < container.size() / 2; k++) {
		bool ordered = container[2 * k] < container[2 * k + 1];
		smaller.push_back(container[2 * k + 1 - ordered]);
		larger.push_back(container[2 * k + ordered]);
	}
	if (container.size() % 2)
		larger.push_back(container[container.size() - 1]);
	
	FordJohnsonSort(larger);
	JacobstalMerge(smaller, larger);

	container = larger;
}

template <class T>
bool IsSorted(T& container) {
	if (container.size() < 2)
		return (true);
	for (unsigned int k = 0; k < container.size() - 1; k++) {
		if (container[k] > container[k + 1])
			return (false);
	}
	return (true);
}

void	GigaTest(int test_count = 10000, int max_vec_len = 1000, int max_value = 10000, int step = 20) {
	srand(time(0));
	std::vector<int> random;
	for (int k = 0, l = 0; k < test_count; k++) {
		if (k % (test_count / step) == 0)
			std::cout << l++ * (100 / step) << "%\n";
		int len = rand() % max_vec_len;
		for (int k = 0; k < len; k++) {
			random.push_back(rand() % max_value);
		}

		FordJohnsonSort(random);		
		if (!IsSorted(random)) {
			std::cout << "Not sorted!\n";
			return ;
		}
		random.clear();
	}
	std::cout << "Allgood!\n";
}

#include <sys/time.h>

void	MeasurePrintTime() {
	static struct timeval start;
	
	if (start.tv_sec == 0 && start.tv_usec == 0) {
		gettimeofday(&start, 0);
	} else {
		struct timeval end;
		gettimeofday(&end, 0);
		std::cout << "Elapsed time: " << 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) << " us\n";
		start.tv_sec = 0;
		start.tv_usec = 0;
	}
}

int main(int argc, char **argv) {

	if (argc == 1) {
		GigaTest(10000, 10000, 10000, 20);
		return (0);
	}

	std::deque<int> d;
	std::vector<int> v;

	try {
		Fill(d, argc - 1, argv + 1);
		Fill(v, argc - 1, argv + 1);
	} catch (const std::invalid_argument& e) {
		std::cerr << "An exception occured: " << e.what() << std::endl;
		return (1);
	}

	std::cout << "Sorting Deque:\n";
	MeasurePrintTime();
	FordJohnsonSort(d);
	MeasurePrintTime();
	
	std::cout << "Sorting Vector:\n";
	MeasurePrintTime();
	FordJohnsonSort(v);
	MeasurePrintTime();

	return (0);
}
