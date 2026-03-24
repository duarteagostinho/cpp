#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor has been called" << std::endl;
	this->type = "Default Wrong";
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor has been called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "WrongAnimal Copy assignment operator has been called" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes no sound..." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const
{
	return(this->type);
}

/* ************************************************************************** */