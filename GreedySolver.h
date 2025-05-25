#ifndef GREEDY_SOLVER_H
#define GREEDY_SOLVER_H

#include "Reader.h"
#include "SolverResult.h"

class GreedySolver {
public:
    static void solve(const TruckDataset& dataset);
    static SolverResult run(const TruckDataset& dataset);
};

#endif // GREEDY_SOLVER_H
