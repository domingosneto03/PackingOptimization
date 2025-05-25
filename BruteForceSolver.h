/**
 * @file BruteForceSolver.h
 * @brief Interface for brute-force and backtracking algorithms to solve the knapsack problem.
 */

#ifndef DA_PROJECT2_BRUTEFORCESOLVER_H
#define DA_PROJECT2_BRUTEFORCESOLVER_H

#include "Reader.h"
#include "SolverResult.h"
#include <vector>
#include <utility>

/**
 * @class BruteForceSolver
 * @brief Provides methods for solving the knapsack problem using brute-force and backtracking.
 */
class BruteForceSolver {
public:
    /**
     * @brief Solves the problem using brute-force and prints a summary.
     * @param dataset The dataset including pallet weights, profits, and truck capacity.
     */
    static void solve(const TruckDataset& dataset);

    /**
     * @brief Runs the brute-force algorithm without printing.
     * @param dataset The dataset to solve.
     * @return SolverResult containing the best solution.
     * @complexity Time: O(2^n), Space: O(n)
     */
    static SolverResult run(const TruckDataset& dataset);

    /**
     * @brief Solves the problem using recursive backtracking and prints a summary.
     * @param dataset The dataset to solve.
     */
    static void solveBacktrack(const TruckDataset& dataset);

    /**
     * @brief Runs the backtracking algorithm without printing.
     * @param dataset The dataset to solve.
     * @return SolverResult containing the best solution.
     * @complexity Time: O(2^n), Space: O(n)
     */
    static SolverResult runBacktrack(const TruckDataset& dataset);
};

#endif // DA_PROJECT2_BRUTEFORCESOLVER_H
