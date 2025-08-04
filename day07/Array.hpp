#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
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

#include "Array.tpp"

#endif // ARRAY_HPP
