#include "templates.hpp"
#include <iostream>

int main(void)
{
    int a = 42, b = 1337;
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    swap(a,b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "Max: " << max(a, b) << std::endl;
    std::cout << "Min: " << min(a, b) << std::endl;
    return (0);
}