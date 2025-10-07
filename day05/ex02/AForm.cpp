#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException("Grade too high");
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException("Grade too low");
}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}
const std::string &AForm::getName() const
{
	return name;
}
bool AForm::getIsSigned() const
{
	return isSigned;
}
int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecuteGrade() const
{
	return executeGrade;
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException(bureaucrat.getName() + " couldn't sign " + name + " because grade too low");
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
	isSigned = true;
}
void AForm::execute(Bureaucrat const & executor) const
{
	if (getExecuteGrade() > executor.getGrade() && getIsSigned())
	{
		executeForm();
	}
	else
	{
		throw (GradeTooLowException("grade too low"));
	}
}
AForm::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::logic_error(msg) {}
AForm::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::logic_error(msg) {}
