#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>

void iter(T *arr, size_t size, F f);

#include "iter.tpp"

#endif // ITER_HPP
