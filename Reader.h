//
// Created by domin on 15/05/2025.
//

#ifndef DA_PROJECT2_READER_H
#define DA_PROJECT2_READER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

struct Pallet {
    int id;
    int weight;
    int profit;
};

struct TruckDataset {
    int capacity;
    int numPallets;
    std::vector<Pallet> pallets;
};

class Reader {
public:
    static TruckDataset readDataset(const std::string& truckFilePath, const std::string& palletFilePath) {
        TruckDataset dataset;

        // Read truck and pallet count
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

        // Read pallets
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
#endif //DA_PROJECT2_READER_H
