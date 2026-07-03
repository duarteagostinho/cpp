#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
class AForm;

class Bureaucrat
{
	private:

		const std::string _name;
		int 			  _grade;

	public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();

	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();

	};
		// Constructors & Destructor
		Bureaucrat();
		Bureaucrat(const std::string &Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		// Overloads
		Bureaucrat &		operator=( Bureaucrat const & rhs );

		// Methods
		const std::string			getName() const;
		int							getGrade() const;
		void						incrementGrade();
		void						decrementGrade();
		void						GradeTooHigh();
		void						GradeTooLow();
		void						signForm(AForm &form);
		void						executeForm(AForm const &form);
		
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
