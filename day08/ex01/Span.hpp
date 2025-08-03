#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int> _container;
        size_t _max;
    public:
        Span(size_t size);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int num);
        void addRange(int range);
        int shortestSpan();
        int longestSpan();
        bool isFull();
};

bool Span::isFull()
{
    return (_container.size() >= _max);
}

Span::Span(size_t max) : _max(max)
{

}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _container = other._container;
        _max = other._max;
    }
    return *this;
}

Span::Span(const Span &other) : _max(other._max), _container(other._container)
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

int Span::shortestSpan()
{
    if (_container.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> temp = _container;
    std::sort(temp.begin(), temp.end());

    int minSpan = std::abs(temp[1] - temp[0]);
    for (std::size_t i = 1; i < temp.size() - 1; ++i)
    {
        int diff = std::abs(temp[i + 1] - temp[i]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
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
    srand(time(0));
    for (int i = 0; i < range; i++)
    {
        try
        {
            addNumber(rand());
        }
        catch(std::exception &e)
        {
            throw(std::out_of_range("out of bound"));
        }
    }
}


#endif //SPAN_HPP