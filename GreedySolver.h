/**
 * @file GreedySolver.h
 * @brief Declares a greedy heuristic-based solver for the knapsack problem.
 */

#ifndef GREEDY_SOLVER_H
#define GREEDY_SOLVER_H

#include "Reader.h"
#include "SolverResult.h"

/**
 * @class GreedySolver
 * @brief Implements a greedy approximation algorithm for pallet selection.
 */
class GreedySolver {
public:
    /**
     * @brief Solves the pallet selection problem using a greedy heuristic and prints results.
     * @param dataset Input dataset with pallet info and truck capacity.
     */
    static void solve(const TruckDataset& dataset);

    /**
     * @brief Runs the greedy approximation algorithm.
     * @param dataset Input dataset to solve.
     * @return SolverResult with selected pallets and total profit.
     * @complexity Time: O(n log n), Space: O(n)
     */
    static SolverResult run(const TruckDataset& dataset);
};

#endif // GREEDY_SOLVER_H
