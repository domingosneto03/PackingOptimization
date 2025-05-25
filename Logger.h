#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
public:
    static void init(const std::string& filename) {
        std::ofstream file(filename);
        file << "Algorithm,Dataset,TimeMs,SolutionValue\n";
    }

    static void log(const std::string& filename, const std::string& algorithm,
                    const std::string& dataset, double timeMs, double value) {
        std::ofstream file(filename, std::ios::app);
        file << algorithm << "," << dataset << "," << timeMs << "," << value << "\n";
    }
};

#endif
