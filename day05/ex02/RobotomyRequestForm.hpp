#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <bits/stdc++.h>


class RobotomyRequestForm : public AForm
{
	private :
		std::string target;
	public :
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		void executeForm() const;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm",72,45), target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm::AForm(other), target(other.target)
{}

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

#endif //ROBOTOMYREQUESTFORM_HPP
