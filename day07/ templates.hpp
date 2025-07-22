#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP


template<typename T>
void swap(T x,T y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}


template<typename T>
void min(T x,T y)
{
    return (x > y ? x : y);
}


template<typename T>
void min(T x,T y)
{
    return (x < y ? x : y);
}

#endif //TEMPLATES_HPP