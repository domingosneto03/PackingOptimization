#include <iostream>
#include "Reader.h"

int main() {
    try {
        // Load dataset 01 (adjust path if necessary)
        std::string truckFile = "../datasets/TruckAndPallets_01.csv";
        std::string palletFile = "../datasets/Pallets_01.csv";

        TruckDataset dataset = Reader::readDataset(truckFile, palletFile);

        std::cout << "Truck Capacity: " << dataset.capacity << "\n";
        std::cout << "Number of Pallets: " << dataset.numPallets << "\n";

        std::cout << "Pallets:\n";
        for (const auto& pallet : dataset.pallets) {
            std::cout << "  ID: " << pallet.id
                      << ", Weight: " << pallet.weight
                      << ", Profit: " << pallet.profit << "\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
