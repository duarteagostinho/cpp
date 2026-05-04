#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:

		const std::string _name;
		int 			  _grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string &Name, int Grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const noexcept;

	};

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		std::string			getName();
		int					getGrade();
		void				incrementGrade();
		void				decrementGrade();
		void				GradeTooHigh();
		void				GradeTooLow();

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */