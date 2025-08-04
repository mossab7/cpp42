#ifndef IDENTIFY_REAL_TYPE_HPP
#define IDENTIFY_REAL_TYPE_HPP

#include <iostream>

class Base
{
public:
	virtual ~Base() {}
	void identify(Base *p) const;
	void identify(Base &p) const;
	Base *generate();
};

Base *Base::generate()
{
	int random = rand() % 3;
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
	catch (const std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::bad_cast &)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::bad_cast &)
	{
	}

	std::cout << "Unknown type" << std::endl;
}

class A : public Base
{
public:
	~A() {}
};

class B : public Base
{
public:
	~B() {}
};
class C : public Base
{
public:
	~C() {}
};
#endif // IDENTIFY_REAL_TYPE_HPP
