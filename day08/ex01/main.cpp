#include "Span.hpp"


int main(void)
{
    Span span(10);

    span.addRange(9);
    std::cout << span.longestSpan() << std::endl;
    std::cout << span.shortestSpan() << std::endl;

}