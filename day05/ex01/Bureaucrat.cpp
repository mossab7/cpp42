#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: name(name), grade(grade)
{
	if (grade < GRADE_MAX)
		throw GradeTooHighException("Grade too high for : " + name);
	if (grade > GRADE_MIN)
		throw GradeTooLowException("Grade too low for : " + name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= GRADE_MAX)
		throw GradeTooHighException("Cannot increment grade above 1");
	--grade;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= GRADE_MIN)
		throw GradeTooLowException("Cannot decrement grade below 150");
	++grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::logic_error(msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::logic_error(msg)
{
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::SignForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signs " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
