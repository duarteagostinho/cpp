#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat constructor has been called" << std::endl;
	this->type = "Cat";
	Brain	*_brain = new Brain();
	this->brain = _brain;
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor has been called" << std::endl;
	delete this->brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat Copy assignment operator has been called" << std::endl;
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

void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */