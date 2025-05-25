#ifndef DYNAMIC_SOLVER_H
#define DYNAMIC_SOLVER_H

#include "Reader.h"
#include "SolverResult.h"

class DynamicSolver {
public:
    static void solve(const TruckDataset& dataset);
    static SolverResult run(const TruckDataset& dataset);
};

#endif // DYNAMIC_SOLVER_H
