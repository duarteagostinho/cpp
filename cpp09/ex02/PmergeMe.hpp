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
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &src);

        static void sortVector(std::vector<int> &vec);
        static void sortDeque(std::deque<int> &deq);

    private:
        struct VectorItem {
            int value;
            size_t id;
        };

        struct VectorPair {
            VectorItem small;
            VectorItem large;
        };

        struct DequeItem {
            int value;
            size_t id;
        };

        struct DequePair {
            DequeItem small;
            DequeItem large;
        };

        static void fordJohnsonVector(std::vector<VectorItem> &items);
        static size_t findVectorItem(const std::vector<VectorItem> &chain, size_t id);
        static void insertVector(std::vector<VectorItem> &chain,
                                 const VectorItem &item, size_t high);
        static std::vector<size_t> jacobsthal(size_t count);

        static void fordJohnsonDeque(std::deque<DequeItem> &items);
        static size_t findDequeItem(const std::deque<DequeItem> &chain, size_t id);
        static void insertDeque(std::deque<DequeItem> &chain,
                                const DequeItem &item, size_t high);
};

std::ostream &operator<<(std::ostream &o, const PmergeMe &i);

#endif
