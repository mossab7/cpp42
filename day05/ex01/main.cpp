#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1("John", 50);
	Bureaucrat b2("Jane", 30);

	Form form1("Form1", 40, 100);
	Form form2("Form2", 60, 30);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	try
	{
		Bureaucrat b3("Invalid", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		form1.beSigned(b1);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		form2.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	b1.SignForm(form1);
	b2.SignForm(form2);
	return 0;
}
