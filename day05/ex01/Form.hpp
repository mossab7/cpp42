#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:
	Form(const std::string &name, int signGrade, int executeGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	const std::string &getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::logic_error
	{
	public:
		GradeTooHighException(const std::string &msg);
	};
	class GradeTooLowException : public std::logic_error
	{
	public:
		GradeTooLowException(const std::string &msg);
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP
