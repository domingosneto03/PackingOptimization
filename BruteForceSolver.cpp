#include "BruteForceSolver.h"
#include <cmath>
#include <iostream>
#include <cstdint>

std::pair<int, std::vector<int>> BruteForceSolver::solve(const TruckDataset& dataset) {
    int n = dataset.numPallets;
    int maxProfit = 0;
    std::vector<int> bestSubset;
    uint64_t totalSubsets = 1ULL << n;
    int exploredSubsets = 0;

    // Iterate over all possible subsets using 64-bit to avoid overflow
    for (uint64_t mask = 0; mask < totalSubsets; ++mask) {
        ++exploredSubsets;

        int totalWeight = 0;
        int totalProfit = 0;
        std::vector<int> currentSubset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1ULL << i)) {
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

    std::cout << "Total subsets explored: " << exploredSubsets << "\n";
    return {maxProfit, bestSubset};
}