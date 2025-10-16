#include "PmergeMe.hpp"

int main()
{
	std::vector<int> arr;
	for (int i = 0; i < 10000; ++i)
		arr.push_back(rand() % 10000);
	arr.push_back(8);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(7);
	arr.push_back(4);
	arr.push_back(6);

	FordJohnson fj;
	fj.sort(arr, std::deque<int>(arr.begin(), arr.end()));
	return 0;

}
