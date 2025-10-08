#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < GRADE_MAX || executeGrade < GRADE_MAX)
		throw GradeTooHighException("Grade too high");
	if (signGrade > GRADE_MIN || executeGrade > GRADE_MIN)
		throw GradeTooLowException("Grade too low");
}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}
const std::string &Form::getName() const
{
	return name;
}
bool Form::getIsSigned() const
{
	return isSigned;
}
int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecuteGrade() const
{
	return executeGrade;
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException("grade too low");
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
	isSigned = true;
}
Form::GradeTooHighException::GradeTooHighException(const std::string &msg)
	: std::logic_error(msg) {}
Form::GradeTooLowException::GradeTooLowException(const std::string &msg)
	: std::logic_error(msg) {}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
		<< "\nSign Grade: " << form.getSignGrade()
		<< "\nExecute Grade: " << form.getExecuteGrade()
		<< "\nStatus: " << (form.getIsSigned() ? "Signed" : "Not signed");

	return os;
}
