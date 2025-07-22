#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array
{
private: 
    T *array;
    unsigned int _size;

    T *dupArray(const Array &other);

public:
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](int index);
    const T &operator[](int index) const;

    unsigned int size() const;
};


template<typename T>
T *Array<T>::dupArray(const Array &other)
{
    T *arr = new T[other._size]();
    for (unsigned int i = 0; i < other._size; ++i)
    {
        arr[i] = other.array[i];
    }
    return arr;
}

template<typename T>
Array<T>::Array() : array(nullptr), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    array = new T[_size]();
}

template<typename T>
Array<T>::Array(const Array &other)
{
    _size = other._size;
    array = dupArray(other);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] array;
        _size = other._size;
        array = dupArray(other);
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}

template<typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template<typename T>
const T &Array<T>::operator[](int index) const
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
        throw std::out_of_range("Index out of range");
    return array[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif // ARRAY_HPP
