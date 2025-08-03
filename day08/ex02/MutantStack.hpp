#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque> 

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() {}
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
    void push_back(T value)
    {
        this->push(value);
    }
};

#endif // MUTANTSTACK_HPP
