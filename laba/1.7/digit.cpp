#include "digit.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctype.h>

Digit::Digit(const std::string& inputFileName, const std::string& outputFileName, const std::string& logFileName) :
    inputFileName(inputFileName),
    outputFileName(outputFileName),
    logFile(logFileName) {}

bool Digit::isAllDigits(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void Digit::processFile() {
    // Решта коду без змін
}

void Digit::printLog() {
    // Решта коду без змін
}


void Digit::processFile() {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Cannot open input file!" << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cout << "Cannot open output file!" << std::endl;
        return;
    }

    std::string line;
    numbers.clear();

    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
    bool allDigits = true;
    for (char c : word) {
        if (!std::isdigit(c)) {
            allDigits = false;
            break;
        }
    }
    if (allDigits) {
        int number = std::stoi(word);
        numbers.push_back(number);
    }
}

    }

    if (!numbers.empty()) {
        outputFile << "found digits:" << std::endl;
        for (int number : numbers) {
            outputFile << number << std::endl;
        }
        outputFile << "amount: " << numbers.size() << std::endl;
    } else {
        outputFile << "digits are not found" << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

void Digit::printLog() {
    logFile << std::setw(10) << "data processing stage:" << std::endl;
    logFile << std::setw(10) << "incoming data: ";

    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cout << "Cannot open input file!" << std::endl;
        return;
    }

    std::string line;

    while (getline(inputFile, line)) {
        logFile << line << std::endl;
    }

    logFile << std::endl;
    logFile << "results:" << std::endl;
    logFile << "found digits:" << std::endl;

    for (int number : numbers) {
        logFile << std::setw(5) << number << std::endl;
    }

    logFile << "amount: " << numbers.size() << std::endl;

    inputFile.close();
    logFile.close();
}
