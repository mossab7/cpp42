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
	template <typename T>
	void addNumbers(T begin, T end);
	void addRange(int range);
	int shortestSpan();
	int longestSpan();
	bool isFull();
};

template <typename T>
void Span::addNumbers(T begin, T end)
{
	while (begin != end)
	{
		if (_container.size() >= _capacity)
		{
			throw std::overflow_error("Span is full");
		}
		_container.push_back(*begin);
		++begin;
	}
}

#endif // SPAN_HPP
