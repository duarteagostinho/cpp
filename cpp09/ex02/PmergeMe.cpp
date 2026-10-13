#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	(void)src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	(void)src;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const PmergeMe &i) {
	(void)i;
	o << "Type: PmergeMe";
	return o;
}

std::vector<size_t> PmergeMe::jacobsthal(size_t count) { // Count = n of pending values
	std::vector<size_t> jacob; // Jacobsthal Vector
	std::vector<size_t> order; // Final order

	if (count == 0) {
		return order;
	}
	jacob.push_back(0); // First nº of sequence
	jacob.push_back(1); // Second nº of sequence
	while (jacob.back() < count) { // Until last jacob nº is at least == pending numbers
		size_t last = jacob.size() - 1;
		jacob.push_back(jacob[last] + 2 * jacob[last - 1]); // Formula (take the last nº and add 2x the second‑last nº)
	}

	order.push_back(0); // Start order
	size_t previous = 1; // Previous group end
	for (size_t i = 3; i < jacob.size(); ++i) { // Start processing jacobsthal vals
		size_t current = jacob[i];
		if (current > count) { // If the jacob nº > nº pending elements
			current = count; // Reduce nº to count, so no wrong index boundaries
		}
		for (size_t index = current; index > previous; --index) { // Starts inserting from the largest nº
			order.push_back(index - 1);
		}
		previous = current;
	}
	for (size_t index = count; index > previous; --index) { // If jacob group doesn't end in count
		order.push_back(index - 1); // We add the remaining indexes
	}
	return order;
}

size_t PmergeMe::findVectorItem(const std::vector<VectorItem> &chain, size_t id) {
	for (size_t i = 0; i < chain.size(); ++i) {
		if (chain[i].id == id) {
			return i;
		}
	}
	return chain.size();
}

void PmergeMe::insertVector(std::vector<VectorItem> &chain, const VectorItem &item, size_t high) {
	size_t low = 0;
	if (high > chain.size()) {
		high = chain.size();
	}
	while (low < high) { // To insert, we check if item.value is > / < than middle.val
		std::cout << "counting\n";
		size_t middle = low + (high - low) / 2;
		if (chain[middle].value < item.value) { // If middle.val < item.val
			low = middle + 1; // Low boundary moves right, value goes after mid
		} else {
			high = middle; // High bound is the mid, so val goes in mid/before
		}
	} // In the end, low is the insert position
	chain.insert(chain.begin() + low, item); 
}

void PmergeMe::fordJohnsonVector(std::vector<VectorItem> &items) {
	if (items.size() <= 1) {
		return; // If 0 || 1 items, it's sorted
	}

	std::vector<VectorPair> pairs; // Every pair
	std::vector<VectorItem> winners; // Larger nºs from pairs
	VectorItem odd; // If items.size == odd
	bool hasOdd = (items.size() % 2) != 0;

	for (size_t i = 0; i + 1 < items.size(); i += 2) { // Makes pairs, and assigns smaller(left) and larger(right)
		std::cout << "counting\n";
		VectorPair pair;
		if (items[i].value <= items[i + 1].value) {
			pair.small = items[i];
			pair.large = items[i + 1];
		} else {
			pair.small = items[i + 1];
			pair.large = items[i];
		}
		pairs.push_back(pair);
		winners.push_back(pair.large);
	}
	if (hasOdd) {
		odd = items.back();
	}

	fordJohnsonVector(winners);

	std::vector<VectorItem> losers; // Now we store the losers into a vec
	for (size_t i = 0; i < winners.size(); ++i) { 
		for (size_t j = 0; j < pairs.size(); ++j) { // We search in the winners vec, and original pairs, for the matching id's
			if (pairs[j].large.id == winners[i].id) { // If there is a match
				losers.push_back(pairs[j].small); // Push loser to the losers vec
				break;
			}
		}
	} // In the end, losers is arranged in the same partner order as the winners.

	std::vector<VectorItem> chain = winners; // Main chain first receives the winners sequence
	if (!losers.empty()) { // If there are still pending losers
		insertVector(chain, losers[0], 0); // Insert the first
	}
	std::vector<size_t> order = jacobsthal(losers.size()); // Now we use jacob to insert losers
	for (size_t i = 1; i < order.size(); ++i) {
		size_t losersIndex = order[i];
		size_t partnerIndex = findVectorItem(chain, winners[losersIndex].id); // Find partner
		insertVector(chain, losers[losersIndex], partnerIndex + 1); // We insert loser beofore it's partner, or in his position
	}
	if (hasOdd) {
		insertVector(chain, odd, chain.size()); // If there is unpaired value, its the last
	}
	items = chain;
}

void PmergeMe::sortVector(std::vector<int> &vec) {
	std::vector<VectorItem> items;
	for (size_t i = 0; i < vec.size(); ++i) {
		VectorItem item;
		item.value = vec[i];
		item.id = i;
		items.push_back(item);
	}
	fordJohnsonVector(items);
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = items[i].value;
	}
}

size_t PmergeMe::findDequeItem(const std::deque<DequeItem> &chain, size_t id) {
	for (size_t i = 0; i < chain.size(); ++i) {
		if (chain[i].id == id) {
			return i;
		}
	}
	return chain.size();
}

void PmergeMe::insertDeque(std::deque<DequeItem> &chain,
		const DequeItem &item, size_t high) {
	size_t low = 0;
	if (high > chain.size()) {
		high = chain.size();
	}
	while (low < high) {
		size_t middle = low + (high - low) / 2;
		if (chain[middle].value < item.value) {
			low = middle + 1;
		} else {
			high = middle;
		}
	}
	chain.insert(chain.begin() + low, item);
}

void PmergeMe::fordJohnsonDeque(std::deque<DequeItem> &items) {
	if (items.size() <= 1) {
		return;
	}

	std::vector<DequePair> pairs;
	std::deque<DequeItem> larger;
	DequeItem odd;
	bool hasOdd = (items.size() % 2) != 0;

	for (size_t i = 0; i + 1 < items.size(); i += 2) {
		DequePair pair;
		if (items[i].value <= items[i + 1].value) {
			pair.small = items[i];
			pair.large = items[i + 1];
		} else {
			pair.small = items[i + 1];
			pair.large = items[i];
		}
		pairs.push_back(pair);
		larger.push_back(pair.large);
	}
	if (hasOdd) {
		odd = items.back();
	}

	fordJohnsonDeque(larger);

	std::deque<DequeItem> pending;
	for (size_t i = 0; i < larger.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].large.id == larger[i].id) {
				pending.push_back(pairs[j].small);
				break;
			}
		}
	}

	std::deque<DequeItem> chain = larger;
	if (!pending.empty()) {
		insertDeque(chain, pending[0], 0);
	}
	std::vector<size_t> order = jacobsthal(pending.size());
	for (size_t i = 1; i < order.size(); ++i) {
		size_t pendingIndex = order[i];
		size_t partnerIndex = findDequeItem(chain, larger[pendingIndex].id);
		insertDeque(chain, pending[pendingIndex], partnerIndex + 1);
	}
	if (hasOdd) {
		insertDeque(chain, odd, chain.size());
	}
	items = chain;
}

void PmergeMe::sortDeque(std::deque<int> &deq) {
	std::deque<DequeItem> items;
	for (size_t i = 0; i < deq.size(); ++i) {
		DequeItem item;
		item.value = deq[i];
		item.id = i;
		items.push_back(item);
	}
	fordJohnsonDeque(items);
	for (size_t i = 0; i < deq.size(); ++i) {
		deq[i] = items[i].value;
	}
}
