/**
 * @file ILPSolver.cpp
 * @brief Implements the interface to a Python-based ILP solver for the knapsack problem.
 */

#include "ILPSolver.h"
#include "SolverResult.h"
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <iostream>

void ILPSolver::solve(const TruckDataset& dataset) {
    SolverResult result = run(dataset);

    std::cout << "\n--- Integer Linear Programming Summary ---\n";
    std::cout << "Max Profit: " << result.solutionValue << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : result.selectedPallets) std::cout << id << " ";
    std::cout << "\nExecution Time: " << result.timeMs << " ms\n";
    std::cout << "Space Complexity: " << result.spaceComplexity << "\n";
}

SolverResult ILPSolver::run(const TruckDataset& dataset) {
    const std::string inputFile = "input.txt";
    const std::string outputFile = "output.txt";

    // Write dataset to input file
    std::ofstream out(inputFile);
    out << dataset.capacity << "\n";
    out << dataset.numPallets << "\n";
    for (const auto& p : dataset.pallets) out << p.weight << " ";
    out << "\n";
    for (const auto& p : dataset.pallets) out << p.profit << " ";
    out << "\n";
    out.close();

    auto start = std::chrono::high_resolution_clock::now();

    // Call external Python script
    int resultCode = system("python ../knapsack_solver.py input.txt output.txt");
    if (resultCode != 0) {
        std::cerr << "Error: Python script failed.\n";
        return {};
    }

    auto end = std::chrono::high_resolution_clock::now();
    double execTime = std::chrono::duration<double, std::milli>(end - start).count();

    // Read and parse results from output file
    std::ifstream in(outputFile);
    double totalProfit;
    in >> totalProfit;

    std::vector<int> selectedIndices;
    int idx;
    while (in >> idx) {
        selectedIndices.push_back(dataset.pallets[idx].id); // Convert index to ID
    }

    return SolverResult {
            .timeMs = execTime,
            .solutionValue = totalProfit,
            .selectedPallets = selectedIndices,
            .spaceComplexity = "O(n)"
    };
}
