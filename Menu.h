/**
 * @file Menu.h
 * @brief Declares the menu interface for interacting with pallet-packing algorithms.
 */

#ifndef MENU_H
#define MENU_H

#include "Reader.h"
#include <string>

/**
 * @class Menu
 * @brief Provides a command-line interface for dataset selection and algorithm execution.
 */
class Menu {
private:
    TruckDataset dataset;

    /**
     * @brief Reads and validates integer input from user within a range.
     * @param prompt Text prompt for the user.
     * @param min Minimum allowed value.
     * @param max Maximum allowed value.
     * @return Validated integer input.
     */
    int getValidatedIntInput(const std::string& prompt, int min, int max);

    /**
     * @brief Displays a formatted section title.
     * @param title The section header to print.
     */
    void printHeader(const std::string& title);

public:
    /**
     * @brief Starts the interactive menu loop.
     */
    void run();
};

#endif // MENU_H
