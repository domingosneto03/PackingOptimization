/**
 * @file Reader.h
 * @brief Provides functionality to read truck and pallet data from CSV files.
 */

#ifndef DA_PROJECT2_READER_H
#define DA_PROJECT2_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

/**
 * @struct Pallet
 * @brief Represents a pallet with an ID, weight, and profit.
 */
struct Pallet {
    int id;
    int weight;
    int profit;
};

/**
 * @struct TruckDataset
 * @brief Represents the dataset containing truck capacity and list of pallets.
 */
struct TruckDataset {
    int capacity;
    int numPallets;
    std::vector<Pallet> pallets;
};

/**
 * @class Reader
 * @brief Reads dataset files for truck capacity and pallets.
 */
class Reader {
public:
    /**
     * @brief Reads and parses the dataset from the provided CSV files.
     * @param truckFilePath Path to the truck dataset CSV file.
     * @param palletFilePath Path to the pallet dataset CSV file.
     * @return A populated TruckDataset structure.
     * @throws std::runtime_error if any file cannot be opened.
     */
    static TruckDataset readDataset(const std::string& truckFilePath, const std::string& palletFilePath) {
        TruckDataset dataset;

        std::ifstream truckFile(truckFilePath);
        if (!truckFile.is_open()) {
            throw std::runtime_error("Could not open truck file: " + truckFilePath);
        }

        std::string line;
        std::getline(truckFile, line); // Skip header
        if (std::getline(truckFile, line)) {
            std::stringstream ss(line);
            std::string capacityStr, palletCountStr;
            std::getline(ss, capacityStr, ',');
            std::getline(ss, palletCountStr, ',');
            dataset.capacity = std::stoi(capacityStr);
            dataset.numPallets = std::stoi(palletCountStr);
        }
        truckFile.close();

        std::ifstream palletFile(palletFilePath);
        if (!palletFile.is_open()) {
            throw std::runtime_error("Could not open pallet file: " + palletFilePath);
        }

        std::getline(palletFile, line); // Skip header
        while (std::getline(palletFile, line)) {
            std::stringstream ss(line);
            std::string idStr, weightStr, profitStr;
            std::getline(ss, idStr, ',');
            std::getline(ss, weightStr, ',');
            std::getline(ss, profitStr, ',');

            Pallet p = {std::stoi(idStr), std::stoi(weightStr), std::stoi(profitStr)};
            dataset.pallets.push_back(p);
        }
        palletFile.close();

        return dataset;
    }
};

#endif // DA_PROJECT2_READER_H
