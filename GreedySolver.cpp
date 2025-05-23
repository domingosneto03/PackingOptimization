#include "GreedySolver.h"
#include "SolverResult.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

SolverResult GreedySolver::solve(const TruckDataset& dataset) {
    struct PalletRatio {
        int id;
        int weight;
        int profit;
        double ratio;
    };

    std::vector<PalletRatio> items;

    for (const auto& p : dataset.pallets) {
        double ratio = static_cast<double>(p.profit) / p.weight;
        items.push_back({p.id, p.weight, p.profit, ratio});
    }

    std::sort(items.begin(), items.end(), [](const PalletRatio& a, const PalletRatio& b) {
        return a.ratio > b.ratio;
    });

    int remainingCapacity = dataset.capacity;
    int totalProfit = 0;
    std::vector<int> selected;

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& item : items) {
        if (item.weight <= remainingCapacity) {
            selected.push_back(item.id);
            totalProfit += item.profit;
            remainingCapacity -= item.weight;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;

    // Output to console for manual run
    std::cout << "\n--- Greedy Approximation Summary ---\n";
    std::cout << "Total Profit: " << totalProfit << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : selected) std::cout << id << " ";
    std::cout << "\n";
    std::cout << "Execution Time: " << exec_time.count() << " ms\n";
    std::cout << "Space Complexity: O(n)\n";

    // Return for performance logging
    return SolverResult {
        .solutionValue = static_cast<double>(totalProfit),
        .timeMs = exec_time.count(),
        .selectedPallets = selected,
        .spaceComplexity = "O(n)"
    };
}
