#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T,typename F>

void iter(T *arr, size_t size, F f)
{

    for (size_t i  = 0; i < size; i++)
    {
        f(arr[i]);        
    }
}

#endif //ITER_HPP