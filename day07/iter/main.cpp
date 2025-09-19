#include <iostream>
#include <string.h>
#include "iter.hpp"

void to_upper(char &c)
{
    c = toupper(c);
}

int main(void)
{
    std::string s("hello world!");
    iter(s,s.size(),to_upper);
    std::cout << s << std::endl;
}