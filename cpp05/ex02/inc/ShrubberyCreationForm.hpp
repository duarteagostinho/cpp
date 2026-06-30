#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:

		std::string	target;

		ShrubberyCreationForm(std::string Target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		void	createFile();
		
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */
