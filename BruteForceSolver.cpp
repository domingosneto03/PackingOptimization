#include "BruteForceSolver.h"
#include <cmath>
#include <iostream>

std::pair<int, std::vector<int>> BruteForceSolver::solve(const TruckDataset& dataset) {
    int n = dataset.numPallets;
    int maxProfit = 0;
    std::vector<int> bestSubset;
    int totalSubsets = 0;

    // Iterate over all possible subsets (2^n possibilities)
    for (int mask = 0; mask < (1 << n); ++mask) {
        ++totalSubsets;

        int totalWeight = 0;
        int totalProfit = 0;
        std::vector<int> currentSubset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                totalWeight += dataset.pallets[i].weight;
                totalProfit += dataset.pallets[i].profit;
                currentSubset.push_back(dataset.pallets[i].id);
            }
        }

        if (totalWeight <= dataset.capacity) {
            if (totalProfit > maxProfit) {
                maxProfit = totalProfit;
                bestSubset = currentSubset;
            }
        }
    }

    std::cout << "Total subsets explored: " << totalSubsets << "\n";
    return {maxProfit, bestSubset};
}
