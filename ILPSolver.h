//
// Created by domin on 24/05/2025.
//

#ifndef DA_PROJECT2_ILPSOLVER_H
#define DA_PROJECT2_ILPSOLVER_H

#include "Reader.h"
#include "SolverResult.h"

class ILPSolver {
public:
    static void solve(const TruckDataset& dataset);
    static SolverResult run(const TruckDataset& dataset);
};


#endif //DA_PROJECT2_ILPSOLVER_H
