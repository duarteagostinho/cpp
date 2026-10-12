#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>
#include <algorithm>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe() {}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const PmergeMe &i) {
	(void)i;
	o << "Type: PmergeMe";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::vector<size_t> PmergeMe::jacobsthal(size_t n) {
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<size_t> J;
	J.push_back(0);
	J.push_back(1);

	while (J.back() < n)
		J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
	order.push_back(0);
	
	size_t prev = 1;
	size_t k = 3;
	while (prev < n && k < J.size()) {
		size_t curr = J[k];
		if (curr > n)
			curr = n;
		size_t i = curr;
		while (i > prev) {
			order.push_back(i - 1);
			i--;
		}
		prev = curr;
		k++;
	}
	return order;
}

size_t insertVec(std::vector<int>& vec, size_t start, size_t end, int value) {
	size_t lower = start;
	size_t higher = end;
	while (lower < higher) {
		size_t mid = lower + (higher - lower) / 2;
		if (vec[mid] < value)
			lower = mid + 1;
		else
			higher = mid;
	}
	vec.insert(vec.begin() + lower, value);
	return lower;
}

static void insertDeq(std::deque<int>& deq, size_t start, size_t end, int value) {
	size_t lower = start;
	size_t higher = end;
	while (lower < higher) {
		size_t mid = lower + (higher - lower) / 2;
		if (deq[mid] < value)
			lower = mid + 1;
		else
			higher = mid;
	}
	deq.insert(deq.begin() + lower, value);
}

void PmergeMe::sortVector(std::vector<int> &vec) {
	if (vec.size() <= 1)
		return;
	
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1]) std::swap(vec[i], vec[i + 1]);
	}

	std::vector<int> sorted;
	for (size_t i = 0; i < vec.size(); i += 2)
		sorted.push_back(vec[i]);
	for (size_t i = 1; i < sorted.size(); ++i) {
		int val = sorted[i];
		int j = (int)i - 1;
		while (j >= 0 && sorted[j] > val) {
			sorted[j + 1] = sorted[j];
			--j;
		}
		sorted[j + 1] = val;
	}

	std::vector<int> remaining;
	for (size_t i = 1; i < vec.size(); i += 2)
		remaining.push_back(vec[i]);

	std::vector<size_t> order = jacobsthal(remaining.size());
	for (size_t idx = 0; idx < order.size() && idx < remaining.size(); ++idx) {
		size_t pos = order[idx];
		if (pos >= remaining.size())
			break;
		insertVec(sorted, 0, sorted.size(), remaining[pos]);
	}
	vec = sorted;
}

void PmergeMe::sortDeque(std::deque<int> &deq) {
	if (deq.size() <= 1)
		return;
	
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		if (deq[i] > deq[i + 1]) std::swap(deq[i], deq[i + 1]);
	}

	std::deque<int> sorted;
	for (size_t i = 0; i < deq.size(); i += 2)
		sorted.push_back(deq[i]);
	for (size_t i = 1; i < sorted.size(); ++i) {
		int val = sorted[i];
		int j = (int)i - 1;
		while (j >= 0 && sorted[j] > val) {
			sorted[j + 1] = sorted[j];
			--j;
		}
		sorted[j + 1] = val;
	}

	std::deque<int> remaining;
	for (size_t i = 1; i < deq.size(); i += 2) 
		remaining.push_back(deq[i]);
	
	std::vector<size_t> order = jacobsthal(remaining.size());
	for (size_t idx = 0; idx < order.size() && idx < remaining.size(); ++idx) {
		size_t pos = order[idx];
		if (pos >= remaining.size())
			break;
		insertDeq(sorted, 0, sorted.size(), remaining[pos]);
	}
	deq = sorted;
}
