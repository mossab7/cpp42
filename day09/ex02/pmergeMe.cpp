#include "PmergeMe.hpp"

Pair::Pair(int a, int b)
{
    if (a >= b)
    {
        winner = a;
        loser = b;
    }
    else
    {
        winner = b;
        loser = a;
    }
}

FordJohnson::FordJohnson() : comparisonCount(0) {}
FordJohnson::FordJohnson(const FordJohnson &other) : comparisonCount(other.comparisonCount) {}
FordJohnson &FordJohnson::operator=(const FordJohnson &other)
{
    if (this != &other)
        comparisonCount = other.comparisonCount;
    return *this;
}
FordJohnson::~FordJohnson() {}

/*------------generateJacobsthalIndices------------*/
std::vector<int> FordJohnson::vecgenerateJacobsthalIndices(int max)
{
    std::vector<int> seq;
    seq.push_back(1);
    seq.push_back(3);
    while (seq.back() < max)
    {
        int n = seq.size();
        int next = seq[n - 1] + 2 * seq[n - 2];
        seq.push_back(next);
    }
    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (seq[i] > max)
        {
            seq.resize(i);
            break;
        }
    }
    return seq;
}

std::deque<int> FordJohnson::deqGenerateJacobsthalIndices(int max)
{
    std::deque<int> seq;
    seq.push_back(1);
    seq.push_back(3);
    while (seq.back() < max)
    {
        int n = seq.size();
        int next = seq[n - 1] + 2 * seq[n - 2];
        seq.push_back(next);
    }
    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (seq[i] > max)
        {
            seq.resize(i);
            break;
        }
    }
    return seq;
}
/*------------generateJacobsthalIndices------------*/

/*----------------------create pairs----------------------*/
std::vector<Pair> FordJohnson::vecCreatePairs(const std::vector<int> &v, bool &hasUnpaired, int &unpaired)
{
    std::vector<Pair> pairs;
    hasUnpaired = false;
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        comparisonCount++;
        pairs.push_back(Pair(v[i], v[i + 1]));
    }
    if (v.size() % 2 == 1)
    {
        hasUnpaired = true;
        unpaired = v.back();
    }
    return pairs;
}

std::deque<Pair> FordJohnson::deqCreatePairs(const std::deque<int> &v, bool &hasUnpaired, int &unpaired)
{
    std::deque<Pair> pairs;
    hasUnpaired = false;
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        comparisonCount++;
        pairs.push_back(Pair(v[i], v[i + 1]));
    }
    if (v.size() % 2 == 1)
    {
        hasUnpaired = true;
        unpaired = v.back();
    }
    return pairs;
}
/*----------------------create pairs----------------------*/

/*----------------------extract winners----------------------*/
std::vector<int> FordJohnson::vecExtractWinners(const std::vector<Pair> &pairs)
{
    std::vector<int> w;
    for (size_t i = 0; i < pairs.size(); ++i)
        w.push_back(pairs[i].winner);
    return w;
}

std::deque<int> FordJohnson::deqExtractWinners(const std::deque<Pair> &pairs)
{
    std::deque<int> w;
    for (size_t i = 0; i < pairs.size(); ++i)
        w.push_back(pairs[i].winner);
    return w;
}
/*----------------------extract winners----------------------*/

/*----------------------sort winners----------------------*/
std::vector<int> FordJohnson::vecSortWinners(const std::vector<int> &winners)
{
    if (winners.size() <= 1)
        return winners;

    if (winners.size() == 2)
    {
        comparisonCount++;
        if (winners[0] > winners[1])
        {
            std::vector<int> temp = winners;
            std::swap(temp[0], temp[1]);
            return temp;
        }
        return winners;
    }
    return vecFordJohnsonSort(winners);
}

std::deque<int> FordJohnson::deqSortWinners(const std::deque<int> &winners)
{
    if (winners.size() <= 1)
        return winners;

    if (winners.size() == 2)
    {
        comparisonCount++;
        if (winners[0] > winners[1])
        {
            std::deque<int> temp = winners;
            std::swap(temp[0], temp[1]);
            return temp;
        }
        return winners;
    }
    return deqFordJohnsonSort(winners);
}
/*----------------------sort winners----------------------*/

/*----------------------merge----------------------*/
std::vector<int> FordJohnson::vecMerge(const std::vector<int> &sortedWinners, const std::vector<Pair> &pairs, bool hasUnpaired, int unpaired)
{
    std::vector<int> result = sortedWinners;
    std::vector<int> losers;
    for (size_t i = 0; i < pairs.size(); ++i)
        losers.push_back(pairs[i].loser);

    std::vector<int> jac = vecgenerateJacobsthalIndices(losers.size());
    std::vector<bool> inserted(losers.size(), false);

    for (size_t j = 0; j < jac.size(); ++j)
    {
        int idx = jac[j] - 1;
        if (idx >= (int)losers.size())
            idx = losers.size() - 1;

        if (!inserted[idx])
        {
            int val = losers[idx];
            size_t pos = lowerBoundCount(result, val, pairs[idx].winner);
            result.insert(result.begin() + pos, val);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < losers.size(); ++i)
    {
        if (!inserted[i])
        {
            int val = losers[i];
            size_t pos = lowerBoundCount(result, val, pairs[i].winner);
            result.insert(result.begin() + pos, val);
            inserted[i] = true;
        }
    }

    if (hasUnpaired)
    {
        size_t pos = lowerBoundCount(result, unpaired, pairs.back().winner);
        result.insert(result.begin() + pos, unpaired);
    }

    return result;
}

std::deque<int> FordJohnson::deqMerge(const std::deque<int> &sortedWinners, const std::deque<Pair> &pairs, bool hasUnpaired, int unpaired)
{
    std::deque<int> result = sortedWinners;
    std::deque<int> losers;
    for (size_t i = 0; i < pairs.size(); ++i)
        losers.push_back(pairs[i].loser);

    std::deque<int> jac = deqGenerateJacobsthalIndices(losers.size());
    std::deque<bool> inserted(losers.size(), false);

    for (size_t j = 0; j < jac.size(); ++j)
    {
        int idx = jac[j] - 1;
        if (idx >= (int)losers.size())
            idx = losers.size() - 1;

        if (!inserted[idx])
        {
            int val = losers[idx];
            size_t pos = lowerBoundCount(result, val, pairs[idx].winner);
            result.insert(result.begin() + pos, val);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < losers.size(); ++i)
    {
        if (!inserted[i])
        {
            int val = losers[i];
            size_t pos = lowerBoundCount(result, val, pairs[i].winner);
            result.insert(result.begin() + pos, val);
            inserted[i] = true;
        }
    }

    if (hasUnpaired)
    {
        size_t pos = lowerBoundCount(result, unpaired, pairs.back().winner);
        result.insert(result.begin() + pos, unpaired);
    }

    return result;
}
/*----------------------merge----------------------*/

/*----------------------ford Johnson----------------------*/
std::vector<int> FordJohnson::vecFordJohnsonSort(const std::vector<int> &vec)
{
    if (vec.size() <= 1)
        return vec;

    bool hasUnpaired = false;
    int unpaired = 0;

    std::vector<Pair> pairs = vecCreatePairs(vec, hasUnpaired, unpaired);
    std::vector<int> winners = vecExtractWinners(pairs);
    std::vector<int> sortedWinners = vecSortWinners(winners);

    return vecMerge(sortedWinners, pairs, hasUnpaired, unpaired);
}

std::deque<int> FordJohnson::deqFordJohnsonSort(const std::deque<int> &deq)
{
    if (deq.size() <= 1)
        return deq;

    bool hasUnpaired = false;
    int unpaired = 0;

    std::deque<Pair> pairs = deqCreatePairs(deq, hasUnpaired, unpaired);
    std::deque<int> winners = deqExtractWinners(pairs);
    std::deque<int> sortedWinners = deqSortWinners(winners);

    return deqMerge(sortedWinners, pairs, hasUnpaired, unpaired);
}
/*----------------------ford Johnson----------------------*/

/*----------------------sort entry point----------------------*/
void FordJohnson::sort(const std::vector<int> &vec, const std::deque<int> &deq)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    resetCount();
    long long start = currentTimeMicro();
    std::vector<int> sorted = vecFordJohnsonSort(vec);
    long long end = currentTimeMicro();
    
    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " 
              << (end - start) << " ms" << " " << comparisonCount <<  std::endl;

              resetCount();
    start = currentTimeMicro();
    std::deque<int> deqSorted = deqFordJohnsonSort(deq);
    end = currentTimeMicro();
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque : " 
              << (end - start) << " ms" << " " << comparisonCount <<  std::endl;
}
/*----------------------sort entry point----------------------*/

long FordJohnson::getComparisonCount() const 
{ 
    return comparisonCount; 
}

void FordJohnson::resetCount() 
{ 
    comparisonCount = 0; 
}

long long FordJohnson::currentTimeMicro()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<long long>(tv.tv_sec) * 1000000 + tv.tv_usec;
}
