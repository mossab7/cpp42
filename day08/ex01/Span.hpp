#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
size_t _capacity;
std::vector<int> _container;

public:
	Span(size_t size);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int num);
	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end);
	void addRange(int range);
	int shortestSpan();
	int longestSpan();
	bool isFull();
};

bool Span::isFull()
{
	return (_container.size() >= _capacity);
}

Span::Span(size_t max) : _capacity(max)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_container = other._container;
		_capacity = other._capacity;
	}
	return *this;
}

Span::Span(const Span &other) : _capacity(other._capacity), _container(other._container)
{
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (isFull())
		throw std::out_of_range("out of bound");
	_container.push_back(num);
}

template <typename InputIterator>

void Span::addNumber(InputIterator begin, InputIterator end)
{
	while (begin != end)
	{
		if (_container.size() >= _capacity)
			throw std::overflow_error("Span is full");
		_container.push_back(*begin);
		++begin;
	}
}

int Span::shortestSpan()
{
	if (_container.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> temp = _container;
	std::sort(temp.begin(), temp.end());

	int minSpan = temp[1] - temp[0];
	for (std::size_t i = 1; i < temp.size() - 1; ++i)
	{
		int diff = temp[i + 1] - temp[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int Span::longestSpan()
{
	if (_container.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int>::const_iterator minIt = std::min_element(_container.begin(), _container.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_container.begin(), _container.end());

	return (*maxIt - *minIt);
}

void Span::addRange(int range)
{
	if (_container.size() + range > _capacity)
		throw(std::out_of_range("addRange: range would exceed max size"));
	static bool seeded = false;
	if (!seeded)
	{
		srand(static_cast<unsigned>(time(0)));
		seeded = true;
	}
	for (int i = 0; i < range; i++)
	{
		addNumber(rand());
	}
}

#endif // SPAN_HPP
