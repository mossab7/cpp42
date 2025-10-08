#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < GRADE_MAX || executeGrade < GRADE_MAX)
		throw GradeTooHighException("Grade too high");
	if (signGrade > GRADE_MIN || executeGrade > GRADE_MIN)
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
		throw (GradeTooLowException(executor.getName() + " couldn't execute " + name + " because grade too low"));
	}
}
AForm::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::logic_error(msg) {}
AForm::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::logic_error(msg) {}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName()
		<< "\nSign Grade: " << form.getSignGrade()
		<< "\nExecute Grade: " << form.getExecuteGrade()
		<< "\nStatus: " << (form.getIsSigned() ? "Signed" : "Not signed");

	return os;
}
