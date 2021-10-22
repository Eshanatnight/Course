#include "knapsack.h"
#include <iostream>

knapsack::knapsack(int _numberOfItems, int capacity, const std::vector<int>& _weights, const std::vector<int>& _value)
    : numberOfItems(_numberOfItems), capacityOfKanpsack(capacity), weights(_weights), value(_value)
{
    knapsackTable.resize(numberOfItems + 1);
    for (auto& vec : knapsackTable)
        vec.resize(capacityOfKanpsack + 1);
}

void knapsack::operator()()
{
    for(int i = 1; i < numberOfItems; ++i)
    {
        for(int w = 1; w < capacityOfKanpsack + 1; ++w)
        {
            int notTakingItem = knapsackTable[i - 1][w];
            int takingItem = 0;

            if(weights[i] <= w)
                takingItem = value[i] + knapsackTable[i - 1][w - weights[i]];

            knapsackTable[i][w] = std::max(notTakingItem, takingItem);
        }
    }

    totalBenifit = knapsackTable[numberOfItems][capacityOfKanpsack];
}


void knapsack::showResult()
{
    std::cout << "Total Benifit: "<< totalBenifit << '\n';
    for(int n = numberOfItems, w = capacityOfKanpsack; n > 0; --n)
    {
        if(knapsackTable[n][w] != 0 && knapsackTable[n][w] != knapsackTable[n - 1][w])
        {
            std::cout << "We take item: #" << n << '\n';
            w = w - weights[n];
        }
    }
}