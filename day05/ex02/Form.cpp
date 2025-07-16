#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException("Grade too high");
    if (signGrade > 150 || executeGrade > 150)
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
        throw GradeTooLowException(bureaucrat.getName() + " couldn't sign " + name + " because grade too low");
    std::cout << bureaucrat.getName() << " signed " << name << std::endl;
    isSigned = true;
}
Form::GradeTooHighException::GradeTooHighException(const std::string &msg)
    : std::logic_error(msg) {}
Form::GradeTooLowException::GradeTooLowException(const std::string &msg)
    : std::logic_error(msg) {}