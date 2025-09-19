#include <iostream>
#include <vector>
#include <cmath>    


void BinaryInsert(std::vector<int>& sorted, int value) {
    int left = 0;
    int right = sorted.size();
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
    }
    sorted.insert(sorted.begin() + left, value);
}

void GenerateSequence(int m, std::vector<int>& seq, int offset = 0) {
    if (m == 0) return;
    if (m == 1) {
        seq.push_back(offset + 1);
        return;
    }

    int k = (int)ceil(m / 2.0);

    GenerateSequence(k - 1, seq, offset);

    seq.push_back(offset + k);

    GenerateSequence(m - k, seq, offset + k);
}

void PairAndSplit(const std::vector<int>& arr,
                  std::vector<int>& winners,
                  std::vector<int>& losers,
                  int& leftover,
                  bool& hasLeftover)
{
    winners.clear();
    losers.clear();
    hasLeftover = false;

    size_t i = 0;
    for (; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) {
            winners.push_back(arr[i]);
            losers.push_back(arr[i + 1]);
        } else {
            winners.push_back(arr[i + 1]);
            losers.push_back(arr[i]);
        }
    }

    if (i < arr.size()) {
        leftover = arr[i];
        hasLeftover = true;
    }
}

std::vector<int> FordJohnsonSort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    std::vector<int> winners, losers;
    int leftover = 0;
    bool hasLeftover = false;
    PairAndSplit(arr, winners, losers, leftover, hasLeftover);

    std::vector<int> sortedWinners = FordJohnsonSort(winners);

    std::vector<int> sequence;
    GenerateSequence(losers.size(), sequence);

    for (size_t i = 0; i < sequence.size(); ++i) {
        int idx = sequence[i] - 1; 
        BinaryInsert(sortedWinners, losers[idx]);
    }

    if (hasLeftover)
        BinaryInsert(sortedWinners, leftover);

    return sortedWinners;
}

int main() {
    std::vector<int> arr;
    arr.push_back(8);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(6);

    std::vector<int> sorted = FordJohnsonSort(arr);

    std::cout << "Sorted array: ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    return 0;
}
