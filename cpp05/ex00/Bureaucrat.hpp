#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
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

		Bureaucrat();
		Bureaucrat(const std::string &Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		const	std::string			getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				GradeTooHigh();
		void				GradeTooLow();

	private:
		const std::string _name;
		int 			  _grade;


};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */
