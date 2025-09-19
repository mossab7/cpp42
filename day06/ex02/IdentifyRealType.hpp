#ifndef IDENTIFY_REAL_TYPE_HPP
#define IDENTIFY_REAL_TYPE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base
{
public:
	virtual ~Base() {}
	void identify(Base *p) const;
	void identify(Base &p) const;
	static Base *generate();
};



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
