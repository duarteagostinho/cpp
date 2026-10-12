# include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>

static double	currTime() {
	struct timespec ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (static_cast<double>(ts.tv_sec) * 1000000.0 + static_cast<double>(ts.tv_nsec) / 1000.0);
}

bool	parse(const std::string &s, int &out) {
	if (s.empty())
		return false;

	for (size_t i = 0; i < s.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}

	long v = std::strtol(s.c_str(), NULL, 10);
	if (v <= 0 || v > INT_MAX)
		return false;
	out = static_cast<int>(v);
	return true;
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int>	vec;
	vec.reserve(ac - 1);
	std::deque<int>	deq;

	for (int i = 1; i < ac; i++) {
		int v;
		if (!parse(av[i], v)) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(v);
		deq.push_back(v);
	}
	std::cout << "Before:";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	double startVec = currTime();
	PmergeMe::sortVector(vec);
	double endVec = currTime();

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << (endVec - startVec) << " us" << std::endl;

	double startDeq = currTime();
	PmergeMe::sortDeque(deq);
	double endDeq = currTime();

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << (endDeq - startDeq) << " us" << std::endl;

	return 0;
}
