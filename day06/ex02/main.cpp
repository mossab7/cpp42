#include "IdentifyRealType.hpp"

int main(void)
{
    Base *base = Base::generate();
    base->identify(base);
    base->identify(*base);
    delete base;
    return 0;
}