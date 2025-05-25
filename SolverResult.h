#ifndef SOLVER_RESULT_H
#define SOLVER_RESULT_H

#include <vector>

struct SolverResult {
    double timeMs;
    double solutionValue;
    int exploredSubsets;
    std::vector<int> selectedPallets;
    std::string spaceComplexity;  // e.g., "O(n)"
};

#endif