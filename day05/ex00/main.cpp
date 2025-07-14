#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("John", 50);
    Bureaucrat b2("Jane", 150);

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    try 
    {
        Bureaucrat b3("Invalid", 0);
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

}