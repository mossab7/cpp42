#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	typedef AForm *(Intern::*FormCreator)(const std::string &);
	AForm *createShrubberyCreationForm(const std::string &target);
	AForm *createRobotomyRequestForm(const std::string &target);
	AForm *createPresidentialPardonForm(const std::string &target);

public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string &formName, const std::string &target);
	class UnknownFormException : public std::logic_error
	{
	public:
		UnknownFormException(const std::string &msg);
	};
};

#endif // INTERN_HPP
