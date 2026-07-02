# include "../inc/AForm.hpp"
#include <exception>
#include <iostream>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

AForm::AForm() : _name("Default"), _signed(false), _toSign(150), _toExecute(150)
{
}

AForm::AForm(const std::string name, int toSign, int toExecute) : _name(name),
	_signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(false),
	_toSign(src._toSign), _toExecute(src._toExecute){
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() 
{
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const AForm &i) {
    (void)i;
    o << "Type: AForm";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void	AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() <= _toSign)
	{
		std::cout << bc.getName() << " signed " << getName() << '\n';
		_signed = true;
	}
	else {
		throw GradeTooLowException();
	}
}
const std::string	AForm::getName() const
{
	return (this->_name);
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_signed == true)
	{
		if (executor.getGrade() <= _toExecute)
			action();
		else
			throw GradeTooLowException();
	}
	else throw FormNotSignedException();
}

void	AForm::action() const
{
}
