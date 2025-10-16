#include "PmergeMe.hpp"

bool isNumber(char *s)
{
	while (*s)
	{
		if (!isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cerr << "usage : ./PmergeMe n numbers to be sorted" << std::endl;
		return (0);
	}
	std::vector<int> arr(ac - 1);
	for (int i = 1; i < ac; i++)
	{
		if (!isNumber(av[i]))
		{
			std::cerr  << "\"" << av[i] << "\"" <<" is not a number" << std::endl;
			return (0);
		}
		arr[i - 1] = atoi(av[i]);
	}
	FordJohnson fj;
	fj.sort(arr, std::deque<int>(arr.begin(), arr.end()));
	return 0;
}
