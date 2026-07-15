#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <iostream>
/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

Base::Base() {
    // std::cout << "Default Constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
Base::~Base() {
    // std::cout << "Default Constructor called" << std::endl;
}
/*
** --------------------------------- OVERLOADS ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

Base*	generate() {	
	switch (std::rand() % 3 + 1)
	{
		case 1:
			return new A;
		case 2:
			return new B;
		case 3:
			return new C;
	}
	return NULL;
}

void	identify(Base *ptr) {
	if (dynamic_cast<A*>(ptr))
		std::cout << "Identified pointer: A\n";
	else if (dynamic_cast<B*>(ptr))
		std::cout << "Identified pointer: B\n"; 
	else if (dynamic_cast<C*>(ptr))
		std::cout << "Identified pointer: C\n";
	else
		std::cout << "Pointer can't be identified\n";
	return;
}


void	identify(Base &ref) {

	try {
		(void)dynamic_cast<A&>(ref);
		std::cout << "Identified reference: A\n";
		return;
	}
	catch(...) {}
	try {
		(void)dynamic_cast<B&>(ref);
		std::cout << "Identified reference: B\n";
		return;
	}
	catch(...) {}

	try {
		(void)dynamic_cast<C&>(ref);
		std::cout << "Identified reference: C\n";
		return;
	}
	catch(...) {}
	return;
}
