#include "ILPSolver.h"
#include <ortools/linear_solver/linear_solver.h>
#include <iostream>
#include <chrono>

using namespace operations_research;

void ILPSolver::solve(const TruckDataset& dataset) {
    SolverResult result = run(dataset);

    std::cout << "\n--- Integer Linear Programming Summary ---\n";
    std::cout << "Max Profit: " << result.solutionValue << "\n";
    std::cout << "Selected Pallets: ";
    for (int id : result.selectedPallets) std::cout << id << " ";
    std::cout << "\n";
    std::cout << "Execution Time: " << result.timeMs << " ms\n";
    std::cout << "Space Complexity: O(n)\n";
}

SolverResult ILPSolver::run(const TruckDataset& dataset) {
    MPSolver solver("KnapsackSolver", MPSolver::CBC_MIXED_INTEGER_PROGRAMMING);

    int n = dataset.numPallets;
    std::vector<const MPVariable*> variables;

    for (int i = 0; i < n; ++i) {
        variables.push_back(solver.MakeIntVar(0, 1, "x" + std::to_string(i)));
    }

    MPConstraint* weightConstraint = solver.MakeRowConstraint(0, dataset.capacity);
    for (int i = 0; i < n; ++i) {
        weightConstraint->SetCoefficient(variables[i], dataset.pallets[i].weight);
    }

    MPObjective* objective = solver.MutableObjective();
    for (int i = 0; i < n; ++i) {
        objective->SetCoefficient(variables[i], dataset.pallets[i].profit);
    }
    objective->SetMaximization();

    auto start = std::chrono::high_resolution_clock::now();
    MPSolver::ResultStatus resultStatus = solver.Solve();
    auto end = std::chrono::high_resolution_clock::now();
    double execTime = std::chrono::duration<double, std::milli>(end - start).count();

    std::vector<int> selected;
    double totalProfit = 0.0;

    if (resultStatus == MPSolver::OPTIMAL) {
        for (int i = 0; i < n; ++i) {
            if (variables[i]->solution_value() > 0.5) {
                selected.push_back(dataset.pallets[i].id);
                totalProfit += dataset.pallets[i].profit;
            }
        }
    } else {
        std::cerr << "No optimal solution found." << std::endl;
    }

    return SolverResult{
            .timeMs = execTime,
            .solutionValue = totalProfit,
            .selectedPallets = selected,
            .spaceComplexity = "O(n)"
    };
}
