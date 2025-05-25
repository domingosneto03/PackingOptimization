/**
 * @file Logger.h
 * @brief Provides simple CSV logging functionality for algorithm performance results.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

/**
 * @class Logger
 * @brief Handles logging of algorithm performance metrics to a CSV file.
 */

class Logger {
public:
    /**
     * @brief Initializes a CSV log file with headers.
     * @param filename Path to the CSV file to create or overwrite.
     */
    static void init(const std::string& filename) {
        std::ofstream file(filename);
        file << "Algorithm,Dataset,TimeMs,SolutionValue\n";
    }

    /**
     * @brief Appends a performance result entry to the CSV file.
     * @param filename Path to the CSV file to append to.
     * @param algorithm Name of the algorithm.
     * @param dataset Name or ID of the dataset used.
     * @param timeMs Execution time in milliseconds.
     * @param value Resulting solution value (profit).
     */
    static void log(const std::string& filename, const std::string& algorithm,
                    const std::string& dataset, double timeMs, double value) {
        std::ofstream file(filename, std::ios::app);
        file << algorithm << "," << dataset << "," << timeMs << "," << value << "\n";
    }
};

#endif
