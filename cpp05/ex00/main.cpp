# include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "\nVALID GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat bc("Boris", 150);
		std::cout << bc << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nINVALID GRADE TEST:" << std::endl;
	try 
	{
		Bureaucrat bc("Thanos", 151);
		std::cout << bc << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\nINVALID INCREMENT TEST:" << std::endl;
	try 
	{
		Bureaucrat bc("Thanos", 1);
		bc.incrementGrade();
		std::cout << bc << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\nINVALID DECREMENT TEST:" << std::endl;
	try 
	{
		Bureaucrat bc("Takumi", 150);
		bc.decrementGrade();
		std::cout << bc << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
