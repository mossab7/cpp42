#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <sys/time.h>
#include <sstream>
#include <cstdlib>

struct Pair
{
	int winner;
	int loser;
	Pair(int a, int b);
};

class FordJohnson
{
private:
	long comparisonCount;

	std::vector<int> vecgenerateJacobsthalIndices(int max);
	std::deque<int> deqGenerateJacobsthalIndices(int max);

	std::vector<Pair> vecCreatePairs(const std::vector<int> &v, bool &hasUnpaired, int &unpaired);
	std::deque<Pair> deqCreatePairs(const std::deque<int> &v, bool &hasUnpaired, int &unpaired);

	std::vector<int> vecExtractWinners(const std::vector<Pair> &pairs);
	std::deque<int> deqExtractWinners(const std::deque<Pair> &pairs);

	template <typename T>
	size_t lowerBoundCount(const T &arr, int value);

	std::vector<int> vecSortWinners(const std::vector<int> &winners);
	std::deque<int> deqSortWinners(const std::deque<int> &winners);

	std::vector<int> vecMerge(const std::vector<int> &sortedWinners, const std::vector<Pair> &pairs, bool hasUnpaired, int unpaired);
	std::deque<int> deqMerge(const std::deque<int> &sortedWinners, const std::deque<Pair> &pairs, bool hasUnpaired, int unpaired);

	std::vector<int> vecFordJohnsonSort(const std::vector<int> &vec);
	std::deque<int> deqFordJohnsonSort(const std::deque<int> &deq);

public:
	FordJohnson();
	FordJohnson(const FordJohnson &other);
	FordJohnson &operator=(const FordJohnson &other);
	~FordJohnson();
	void sort(const std::vector<int> &vec, const std::deque<int> &deq);
	long getComparisonCount() const;
	void resetCount();
	static long long currentTimeMicro();
};

// Template method definition must stay in header
template <typename T>
size_t FordJohnson::lowerBoundCount(const T &arr, int value)
{
	size_t low = 0, high = arr.size();
	while (low < high)
	{
		size_t mid = (low + high) / 2;
		comparisonCount++;
		if (arr[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

#endif
