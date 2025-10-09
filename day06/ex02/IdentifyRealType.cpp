#include "IdentifyRealType.hpp"

Base::Base() {}

Base::Base(const Base &other)
{
	(void)other;
}

Base &Base::operator=(const Base &other)
{
	(void)other;
	return (*this);
}

Base::~Base() {}

Base *Base::generate()
{
    srand(time(NULL));
	static int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base *p) const
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base &p) const
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	std::cerr << "Unknown type" << std::endl;
}
