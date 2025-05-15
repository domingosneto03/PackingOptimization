//
// Created by domin on 15/05/2025.
//

#ifndef DA_PROJECT2_BRUTEFORCESOLVER_H
#define DA_PROJECT2_BRUTEFORCESOLVER_H


#include "Reader.h"
#include <vector>
#include <utility>

class BruteForceSolver {
public:
    static void solve(const TruckDataset& dataset);
    static void solveBacktrack(const TruckDataset& dataset);
};


#endif //DA_PROJECT2_BRUTEFORCESOLVER_H
