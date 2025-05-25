/**
 * @file ILPSolver.h
 * @brief Declares the ILP-based solver interface for the pallet selection problem.
 */

#ifndef DA_PROJECT2_ILPSOLVER_H
#define DA_PROJECT2_ILPSOLVER_H

#include "Reader.h"
#include "SolverResult.h"

/**
 * @class ILPSolver
 * @brief Provides a wrapper around an external ILP (Integer Linear Programming) solver.
 *
 * Uses a Python-based script to solve the 0/1 knapsack problem optimally.
 */
class ILPSolver {
public:
    /**
     * @brief Solves the pallet selection problem using ILP and prints a summary.
     * @param dataset The dataset containing pallets and truck capacity.
     */
    static void solve(const TruckDataset& dataset);

    /**
     * @brief Executes the ILP solver via a Python script and parses the result.
     * @param dataset The input dataset.
     * @return SolverResult containing execution time, selected items, and solution value.
     */
    static SolverResult run(const TruckDataset& dataset);
};

#endif // DA_PROJECT2_ILPSOLVER_H
