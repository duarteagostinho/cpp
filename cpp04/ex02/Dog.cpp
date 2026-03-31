#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog constructor has been called" << std::endl;
	this->type = "Dog";
	Brain	*_brain = new Brain();
	this->brain = _brain;
}

Dog::Dog( const Dog & src )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor has been called" << std::endl;
	delete this->brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog Copy assignment operator has been called" << std::endl;
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const 
{
	std::cout << "Woof! Woof!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */