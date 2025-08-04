#include <algorithm>

template <typename Container>
typename Container::iterator easyfind(Container &container, int val)
{
	return std::find(container.begin(), container.end(), val);
}
