#include "Form.hpp"
#include <string>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

Form::Form() : _name("Default"), _signed(false), _toSign(150), _toExecute(150)
{
	// std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, int toSign, int toExecute) : _name(name),
	_signed(false), _toSign(toSign), _toExecute(toExecute)
{
	if (toSign < 1 || toExecute < 1)
		throw GradeTooHighException();
	else if (toSign > 150 || toExecute > 150)
		throw GradeTooLowException();
	// std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(false),
	_toSign(src._toSign), _toExecute(src._toExecute){
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

Form &Form::operator=(const Form &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Form &i) {
    (void)i; // Evita erro de 'unused parameter' até adicionares lógica
    o << "Type: Form";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

void	Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() < _toSign)
		throw GradeTooHighException();
	else if (bc.getGrade() > _toSign)
		throw GradeTooLowException();
	else
	{
		std::cout << bc.getName() << " signed " << getName() << std::endl;
		_signed = true;
	}
}

const std::string	Form::getName() const
{
	return (this->_name);
}
