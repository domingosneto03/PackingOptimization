/**
 * @file SolverResult.h
 * @brief Defines a structure to hold the result of an algorithm's execution.
 */

#ifndef SOLVER_RESULT_H
#define SOLVER_RESULT_H

#include <vector>
#include <string>

/**
 * @struct SolverResult
 * @brief Contains the result of an algorithm run, including timing, solution quality, and space usage.
 */
struct SolverResult {
    double timeMs;                  ///< Execution time in milliseconds
    double solutionValue;          ///< Total profit or cost of the solution
    int exploredSubsets;           ///< Number of subsets explored (only for brute-force)
    std::vector<int> selectedPallets; ///< IDs of selected pallets
    std::string spaceComplexity;   ///< Space complexity in Big-O notation
};

#endif
