#ifndef MENU_H
#define MENU_H

#include "Reader.h"
#include <string>

class Menu {
private:
    TruckDataset dataset;

    // Utility function to safely read an integer from string input
    int getValidatedIntInput(const std::string& prompt, int min, int max);

    // Print a formatted section header
    void printHeader(const std::string& title);

public:
    void run();
};

#endif // MENU_H
