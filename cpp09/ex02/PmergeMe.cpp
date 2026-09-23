#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

PMergeMe::PMergeMe() {
    // std::cout << "Default Constructor called" << std::endl;
}

PMergeMe::PMergeMe(const PMergeMe &src) {
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PMergeMe::~PMergeMe() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

PMergeMe &PMergeMe::operator=(const PMergeMe &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const PMergeMe &i) {
    (void)i; // Evita erro de 'unused parameter' até adicionares lógica
    o << "Type: PMergeMe";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

// Add methods here...
