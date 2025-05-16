#include "DynamicSolver.h"
#include <iostream>
#include <vector>
#include <chrono>

void DynamicSolver::solve(const TruckDataset& dataset) {
    int capacity = dataset.capacity;
    int n = dataset.numPallets;

    std::vector<int> dp(capacity + 1, 0);
    std::vector<std::vector<bool>> taken(n, std::vector<bool>(capacity + 1, false));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; ++i) {
        int w = dataset.pallets[i].weight;
        int p = dataset.pallets[i].profit;
        for (int j = capacity; j >= w; --j) {
            if (dp[j - w] + p > dp[j]) {
                dp[j] = dp[j - w] + p;
                taken[i][j] = true;
            }
        }
    }

    // Reconstruct solution
    int maxProfit = dp[capacity];
    std::vector<int> selected;
    int w = capacity;

    for (int i = n - 1; i >= 0; --i) {
        if (taken[i][w]) {
            selected.push_back(dataset.pallets[i].id);
            w -= dataset.pallets[i].weight;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;

    std::cout << "\n--- Dynamic Programming Summary ---\n";
    std::cout << "Max Profit: " << maxProfit << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : selected) std::cout << id << " ";
    std::cout << "\n";
    std::cout << "Execution Time: " << exec_time.count() << " ms\n";
    std::cout << "Space Complexity: O(n * W) for tracking, or O(W) for pure value storage\n";
}
