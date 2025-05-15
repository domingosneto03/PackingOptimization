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
    static std::pair<int, std::vector<int>> solve(const TruckDataset& dataset);
};


#endif //DA_PROJECT2_BRUTEFORCESOLVER_H
