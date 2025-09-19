#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Data.hpp"

typedef unsigned long long uintptr_t;

class Serialization
{
public:
	Serialization();
	Serialization(const Serialization &other);
	~Serialization();
	Serialization &operator=(const Serialization &other);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif // SERIALIZATION_HPP
