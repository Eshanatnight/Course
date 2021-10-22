#pragma once
#include <vector>

class knapsack
{
    private:
    int numberOfItems;
    int capacityOfKanpsack;
    std::vector<std::vector<int>> knapsackTable;
    int totalBenifit = 0;
    std::vector<int> weights;
    std::vector<int> value;

    public:
    knapsack(int numberOfItems, int capacity, const std::vector<int>& weight, const std::vector<int>& value);


    void operator()();
    void showResult();
};

