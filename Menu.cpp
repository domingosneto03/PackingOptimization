#include "Menu.h"
#include "BruteForceSolver.h"
#include "DynamicSolver.h"
#include "GreedySolver.h"
#include "Logger.h"
#include <iostream>
#include <string>
#include <limits>
#include <chrono>

// Helper function to get validated integer input from user string input
int Menu::getValidatedIntInput(const std::string& prompt, int min, int max) {
    std::string input;
    int value = -1;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        try {
            value = std::stoi(input);
            if (value >= min && value <= max) {
                return value;
            } else {
                std::cout << "Please enter a number between " << min << " and " << max << ".\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
}

void Menu::printHeader(const std::string& title) {
    std::cout << "=========================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "=========================" << std::endl;
}

void Menu::run() {
    while (true) {
        printHeader("Pallet Packing System");

        int datasetChoice = getValidatedIntInput("Choose a dataset [1-10]: ", 0, 10);
        if (datasetChoice == 0) {
            std::cout << "Exiting...\n";
            break;
        }

        std::string base = (datasetChoice < 5) ? "../datasets/" : "../datasets-extra/";
        std::string index = (datasetChoice < 10 ? "0" : "") + std::to_string(datasetChoice);
        std::string truckFile = base + "TruckAndPallets_" + index + ".csv";
        std::string palletFile = base + "Pallets_" + index + ".csv";

        try {
            dataset = Reader::readDataset(truckFile, palletFile);
            std::cout << "\nDataset Loaded:\n";
            std::cout << "Truck Capacity: " << dataset.capacity << "\n";
            std::cout << "Number of Pallets: " << dataset.numPallets << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Error reading dataset: " << e.what() << std::endl;
            continue;
        }

        int option = -1;
        while (true) {
            std::cout << "\nMain Menu:" << std::endl;
            std::cout << "1. Run Brute Force Algorithm" << std::endl;
            std::cout << "2. Run Brute Force with Backtracking" << std::endl;
            std::cout << "3. Run Dynamic Programming Algorithm" << std::endl;
            std::cout << "4. Run Greedy Approximation Algorithm" << std::endl;
            std::cout << "5. Run ILP/Other Advanced Algorithm" << std::endl;
            std::cout << "6. Compare Algorithm Performance" << std::endl;
            std::cout << "7. Choose Another Dataset" << std::endl;
            std::cout << "0. Exit" << std::endl;

            option = getValidatedIntInput("Select an option: ", 0, 7);

            if (option == 0) {
                std::cout << "Exiting..." << std::endl;
                return;
            } else if (option == 7) {
                std::cout << "Returning to dataset selection...\n";
                break;  // break inner loop to choose another dataset
            }

            switch (option) {
                case 1:
                    printHeader("Brute Force Algorithm");
                    BruteForceSolver::solve(dataset);
                    break;
                case 2:
                    printHeader("Brute Force with Backtracking");
                    BruteForceSolver::solveBacktrack(dataset);
                    break;
                case 3:
                    printHeader("Dynamic Programming Algorithm");
                    DynamicSolver::solve(dataset);
                    break;
                case 4:
                    printHeader("Greedy Approximation Algorithm");
                    GreedySolver::solve(dataset);
                    break;
                case 5:
                    printHeader("ILP/Other Advanced Algorithm");
                    std::cout << "[TODO] Running ILP/Other Advanced Algorithm..." << std::endl;
                    break;
                case 6:
                    printHeader("Algorithm Performance Comparison");

                    std::string datasetName = "dataset_" + std::to_string(datasetChoice);
                    std::string logFile = "performance_results.csv";
                    Logger::init(logFile);

                    auto runAndLog = [&](const std::string& name, SolverResult (*solver)(const TruckDataset&)) {
                        const int repetitions = 3;
                        double totalTime = 0.0;
                        double totalValue = 0.0;

                        for (int i = 0; i < repetitions; ++i) {
                            SolverResult result = solver(dataset);
                            totalTime += result.timeMs;
                            totalValue += result.solutionValue;
                        }

                        double avgTime = totalTime / repetitions;
                        double avgValue = totalValue / repetitions;

                        Logger::log(logFile, name, datasetName, avgTime, avgValue);
                        std::cout << name << " -> Avg Time: " << avgTime << " ms, Avg Value: " << avgValue << "\n";
                    };

                    runAndLog("BruteForce", BruteForceSolver::run);
                    runAndLog("Backtrack", BruteForceSolver::runBacktrack);
                    runAndLog("Dynamic", DynamicSolver::run);
                    runAndLog("Greedy", GreedySolver::run);
                    // TODO: run ILP if implemented

                    std::cout << "Performance results saved to: " << logFile << std::endl;
                    break;
            }
        }
    }
}
