#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>

class PMergeMe {
    public:
        // Constructors & Destructor
        PMergeMe();                                  // Default
        PMergeMe(const PMergeMe &src);            // Copy
        ~PMergeMe();                                 // Destructor

        // Operators
        PMergeMe &operator=(const PMergeMe &src); // Copy Assignment

    private:
        // Attributes go here
};

// Stream Operator Overload
std::ostream &operator<<(std::ostream &o, const PMergeMe &i);

#endif
