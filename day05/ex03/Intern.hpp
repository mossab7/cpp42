#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm *(*FormCreator)(const std::string &target);

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        AForm *makeForm(const std::string &formName, const std::string &target);
    class UnknownFormException : public std::logic_error
    {
        public:
            UnknownFormException(const std::string &msg);
    };
    private:
        static AForm *createShrubberyCreationForm(const std::string &target)
        {
            return new ShrubberyCreationForm(target);
        }
        static AForm *createRobotomyRequestForm(const std::string &target)
        {
            return new RobotomyRequestForm(target);
        }
        static AForm *createPresidentialPardonForm(const std::string &target)
        {
            return new PresidentialPardonForm(target);
        }
};

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
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
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };
    std::string formNames[] = {
        "ShrubberyCreation",
        "RobotomyRequest",
        "PresidentialPardon"
    };
    for (size_t i = 0; i < sizeof(formNames) / sizeof(formNames[0]); ++i)
    {
        if (formName == formNames[i])
            return creators[i](target);
    }
    throw UnknownFormException("Unknown form type: " + formName);
}


#endif // INTERN_HPP