# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <iostream>

int main()
{
	std::cout << "\nVALID GRADE TO SIGN:" << std::endl;
	try 
	{
		Bureaucrat	bc("Boris", 150);
		Form		textForm("Form", 150, 150);
		textForm.beSigned(bc);
		std::cout << bc << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\nINVALID GRADE TO SIGN:" << std::endl;
	try 
	{
		Bureaucrat	bc("Boris", 150);
		Form		textForm("Form", 100, 100);
		textForm.beSigned(bc);
		std::cout << bc << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

}
