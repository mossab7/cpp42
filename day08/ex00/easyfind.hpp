#ifndef EASYFIND_HPP
#define EASYFIND_HPP


template <typename Container>
typename Container::iterator easyfind(Container& container, int val)
{
    for (auto iter = container.begin(); iter != container.end(); ++iter)
    {
        if (*iter == val)
            return (iter);
    }
    return (container.end());
}


#endif //EASYFIND_HPP
