#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade)
	: _name(Name),
	 _grade(Grade)
{
	std::cout << "Bureaucrat constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor has been called." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::incrementGrade()
{

	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName() 
{
	return (this->_name);
}

int Bureaucrat::getGrade()
{
	return (this->_grade);
}




/* ************************************************************************** */