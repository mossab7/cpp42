#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define GRADE_MIN 150
#define GRADE_MAX 1

class Form;
class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void SignForm(Form &form);
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif // BUREAUCRAT_HPP
