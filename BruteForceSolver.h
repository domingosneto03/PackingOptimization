//
// Created by domin on 15/05/2025.
//

#ifndef DA_PROJECT2_BRUTEFORCESOLVER_H
#define DA_PROJECT2_BRUTEFORCESOLVER_H


#include "Reader.h"
#include "SolverResult.h"
#include <vector>
#include <utility>

class BruteForceSolver {
public:
    static void solve(const TruckDataset& dataset);
    static SolverResult run(const TruckDataset& dataset);
    static void solveBacktrack(const TruckDataset& dataset);
    static SolverResult runBacktrack(const TruckDataset& dataset);

};


#endif //DA_PROJECT2_BRUTEFORCESOLVER_H
