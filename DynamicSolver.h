/**
 * @file DynamicSolver.h
 * @brief Declares the interface for solving the knapsack problem using dynamic programming.
 */

#ifndef DYNAMIC_SOLVER_H
#define DYNAMIC_SOLVER_H

#include "Reader.h"
#include "SolverResult.h"

/**
 * @class DynamicSolver
 * @brief Provides a dynamic programming approach for solving the 0/1 knapsack problem.
 */
class DynamicSolver {
public:
    /**
     * @brief Solves the problem and prints a summary using dynamic programming.
     * @param dataset Dataset with pallet weights, profits, and truck capacity.
     */
    static void solve(const TruckDataset& dataset);

    /**
     * @brief Executes the dynamic programming algorithm.
     * @param dataset The dataset to solve.
     * @return SolverResult containing the best solution found.
     * @complexity Time: O(n * W), Space: O(n * W)
     */
    static SolverResult run(const TruckDataset& dataset);
};

#endif // DYNAMIC_SOLVER_H
