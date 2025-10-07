#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::UnknownFormException::UnknownFormException(const std::string &msg)
    : std::logic_error(msg)
{
}
Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    FormCreator creators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    std::string formNames[] = {
        "ShrubberyCreation",
        "RobotomyRequest",
        "PresidentialPardon"
    };
    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formName == formNames[i])
            return (this->*creators[i])(target);}
    throw UnknownFormException("Unknown form type: " + formName);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}