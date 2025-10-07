#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", 1);
		AForm *form;
		form = new PresidentialPardonForm("TopSecret");
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		for (int i = 0; i < PPF_SIGN_GRADE; i++)
			john.decrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", 1);
		AForm *form;
		form = new ShrubberyCreationForm("TopSecret");
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		for (int i = 0; i < SCF_SIGN_GRADE; i++)
			john.decrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", 1);
		AForm *form;
		form = new RobotomyRequestForm("TopSecret");
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		for (int i = 0; i < RRF_SIGN_GRADE; i++)
			john.decrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	return (0);
}
