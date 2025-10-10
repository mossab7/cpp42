#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <cstddef>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &other);
	~MutantStack();

	MutantStack &operator=(const MutantStack &other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	template <typename F>
	void push_range(F begin, F end);

};


template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
	: std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
template <typename F>
void MutantStack<T>::push_range(F begin, F end)
{
	while (begin != end)
	{
		this->push(*begin);
		++begin;
	}

}

#endif // MUTANTSTACK_HPP
