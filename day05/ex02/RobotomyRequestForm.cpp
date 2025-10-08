#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", RR_SIGN_GRADE, RR_EXEC_GRADE), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm::AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void RobotomyRequestForm::executeForm() const
{
	srand(time(0));
	if (rand() % 10 < 5)
	{
		std::cout << "Bzzzz... " << target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed for " << target << "." << std::endl;
	}
	return;
}
