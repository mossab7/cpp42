#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

public:
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	const std::string &getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void executeForm() const = 0;
	void execute(Bureaucrat const & executor) const;
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

#endif // AFORM_HPP
