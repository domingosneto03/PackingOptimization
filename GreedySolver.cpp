/**
 * @file GreedySolver.cpp
 * @brief Implements a greedy heuristic for solving the knapsack problem.
 * @details Selects items based on profit-to-weight ratio until capacity is full.
 */

#include "GreedySolver.h"
#include "SolverResult.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void GreedySolver::solve(const TruckDataset& dataset) {
    SolverResult result = run(dataset);

    std::cout << "\n--- Greedy Approximation Summary ---\n";
    std::cout << "Total Profit: " << result.solutionValue << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : result.selectedPallets) std::cout << id << " ";
    std::cout << "\nExecution Time: " << result.timeMs << " ms\n";
    std::cout << "Space Complexity: " << result.spaceComplexity << "\n";
}

SolverResult GreedySolver::run(const TruckDataset& dataset) {
    struct PalletRatio {
        int id;
        int weight;
        int profit;
        double ratio;
    };

    std::vector<PalletRatio> items;

    // Calculate profit-to-weight ratio for each pallet
    for (const auto& p : dataset.pallets) {
        double ratio = static_cast<double>(p.profit) / p.weight;
        items.push_back({p.id, p.weight, p.profit, ratio});
    }

    // Sort pallets by decreasing ratio
    std::sort(items.begin(), items.end(), [](const PalletRatio& a, const PalletRatio& b) {
        return a.ratio > b.ratio;
    });

    int remainingCapacity = dataset.capacity;
    int totalProfit = 0;
    std::vector<int> selected;

    auto start = std::chrono::high_resolution_clock::now();

    // Pick items greedily while they fit
    for (const auto& item : items) {
        if (item.weight <= remainingCapacity) {
            selected.push_back(item.id);
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;

    return SolverResult{
            .timeMs = exec_time.count(),
            .solutionValue = static_cast<double>(totalProfit),
            .selectedPallets = selected,
            .spaceComplexity = "O(n)"
    };
}
