#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", GRADE_MIN - 1);
		AForm *form;
		Intern intern;
		form = intern.makeForm("PresidentialPardon", "TopSecret");
		std::cout << *form << std::endl;
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		for (int i = 0; i < GRADE_MIN - PP_SIGN_GRADE; i++)
			john.incrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", GRADE_MIN);
		AForm *form;
		Intern intern;
		form = intern.makeForm("ShrubberyCreation", "TopSecret");
		std::cout << *form << std::endl;
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		for (int i = 0; i < GRADE_MIN - SC_SIGN_GRADE; i++)
			john.incrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	{
		Bureaucrat john("John", GRADE_MIN);
		AForm *form;
		Intern intern;
		form = intern.makeForm("RobotomyRequest", "TopSecret");
		std::cout << *form << std::endl;
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		for (int i = 0; i < GRADE_MIN - RR_SIGN_GRADE; i++)
			john.incrementGrade();
		try
		{
			john.signForm(*form);
			john.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *form << std::endl;
		delete form;
	}
	std::cout << "/*------------------------------------------------------------*/" << std::endl;
	return (0);
}
