# include "Bureaucrat.hpp"
# include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	// std::cout << "Default Bureaucrat constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : _name(Name), _grade(Grade)
{
	// std::cout << "Bureaucrat constructor has been called" << std::endl;
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade)
{
	// std::cout << "Copy constructor has been called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor has been called." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs.getGrade();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Bureaucrat::incrementGrade()
{
	if (_grade < 2)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade > 149)
		throw GradeTooLowException();
	else 
		this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (GradeTooHighException &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}




/* ************************************************************************** */
