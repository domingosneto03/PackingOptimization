#include "Menu.h"
#include <iostream>
#include <string>
#include <limits>

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
    printHeader("Pallet Packing System");

    int datasetChoice = getValidatedIntInput("Choose a dataset [1-10]: ", 1, 10);

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
        return;
    }

    int option = -1;
    while (option != 0) {
        std::cout << "\nMain Menu:" << std::endl;
        std::cout << "1. Run Brute Force Algorithm" << std::endl;
        std::cout << "2. Run Dynamic Programming Algorithm" << std::endl;
        std::cout << "3. Run Greedy Approximation Algorithm" << std::endl;
        std::cout << "4. Run ILP/Other Advanced Algorithm" << std::endl;
        std::cout << "5. Compare Algorithm Performance" << std::endl;
        std::cout << "0. Exit" << std::endl;

        option = getValidatedIntInput("Select an option: ", 0, 5);

        switch (option) {
            case 1:
                printHeader("Brute Force Algorithm");
                // TODO: Implement Brute Force Algorithm
                std::cout << "[TODO] Running Brute Force Algorithm..." << std::endl;
                break;
            case 2:
                printHeader("Dynamic Programming Algorithm");
                // TODO: Implement Dynamic Programming Algorithm
                std::cout << "[TODO] Running Dynamic Programming Algorithm..." << std::endl;
                break;
            case 3:
                printHeader("Greedy Approximation Algorithm");
                // TODO: Implement Greedy Approximation Algorithm
                std::cout << "[TODO] Running Greedy Approximation Algorithm..." << std::endl;
                break;
            case 4:
                printHeader("ILP/Other Advanced Algorithm");
                // TODO: Implement ILP or Alternative Algorithm
                std::cout << "[TODO] Running ILP/Other Advanced Algorithm..." << std::endl;
                break;
            case 5:
                printHeader("Algorithm Performance Comparison");
                // TODO: Compare performance (time, space, accuracy)
                std::cout << "[TODO] Comparing Algorithms..." << std::endl;
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
        }
    }
}