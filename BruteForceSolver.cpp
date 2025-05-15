#include "BruteForceSolver.h"
#include <cmath>
#include <iostream>
#include <cstdint>
#include <chrono>

namespace {
    void backtrack(const TruckDataset& dataset, int index, int currentWeight, int currentProfit,
                   int& maxProfit, std::vector<int>& currentSubset, std::vector<int>& bestSubset) {
        if (index == dataset.pallets.size()) {
            if (currentWeight <= dataset.capacity && currentProfit > maxProfit) {
                maxProfit = currentProfit;
                bestSubset = currentSubset;
            }
            return;
        }

        // Include current item if it doesn't exceed capacity
        int nextWeight = currentWeight + dataset.pallets[index].weight;
        if (nextWeight <= dataset.capacity) {
            currentSubset.push_back(dataset.pallets[index].id);
            backtrack(dataset, index + 1,
                      nextWeight,
                      currentProfit + dataset.pallets[index].profit,
                      maxProfit, currentSubset, bestSubset);
            currentSubset.pop_back();
        }

        // Skip current item
        backtrack(dataset, index + 1, currentWeight, currentProfit, maxProfit, currentSubset, bestSubset);
    }
}

void BruteForceSolver::solve(const TruckDataset& dataset) {
    int n = dataset.numPallets;
    int maxProfit = 0;
    std::vector<int> bestSubset;
    uint64_t totalSubsets = 1ULL << n;
    int exploredSubsets = 0;

    auto start = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;

    std::cout << "\n--- Brute Force Summary ---\n";
    std::cout << "Total subsets explored: " << exploredSubsets << "\n";
    std::cout << "Max Profit: " << maxProfit << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : bestSubset) std::cout << id << " ";
    std::cout << "\n";
    std::cout << "Execution Time: " << exec_time.count() << " ms\n";
    std::cout << "Space Complexity: O(n)\n";
}

void BruteForceSolver::solveBacktrack(const TruckDataset& dataset) {
    int maxProfit = 0;
    std::vector<int> currentSubset;
    std::vector<int> bestSubset;

    auto start = std::chrono::high_resolution_clock::now();
    backtrack(dataset, 0, 0, 0, maxProfit, currentSubset, bestSubset);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;

    std::cout << "\n--- Brute Force with Backtracking Summary ---\n";
    std::cout << "Max Profit: " << maxProfit << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : bestSubset) std::cout << id << " ";
    std::cout << "\n";
    std::cout << "Execution Time: " << exec_time.count() << " ms\n";
    std::cout << "Space Complexity: O(n)\n";
}
