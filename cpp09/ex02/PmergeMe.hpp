#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <string>
# include <algorithm>
# include <ctime>
# include <sys/time.h>
# include <cstdlib>
# include <cctype>
# include <climits>

class PmergeMe {
    public:
        // Constructors & Destructor
        PmergeMe();                                  // Default
        PmergeMe(const PmergeMe &src);            // Copy
        ~PmergeMe();                                 // Destructor

        // Operators
        PmergeMe &operator=(const PmergeMe &src); // Copy Assignment

    	static void sortVector(std::vector<int> &vec);
		static void sortDeque(std::deque<int> &deq);
		static std::vector<size_t> jacobsthal(size_t n);
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const PmergeMe &i);

#endif
