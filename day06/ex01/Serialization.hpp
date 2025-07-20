#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <sstream>
#include <string>

class Data
{
    public:
        int value;
};

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

Serialization::Serialization() {}
Serialization::Serialization(const Serialization &other) 
{
    (void)other;
}
Serialization::~Serialization() {}
Serialization &Serialization::operator=(const Serialization &other)
{
    (void)other;
    return *this;
}
uintptr_t Serialization::serialize(Data *ptr) 
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serialization::deserialize(uintptr_t raw) 
{
    return reinterpret_cast<Data *>(raw);
}
      

#endif // SERIALIZATION_HPP