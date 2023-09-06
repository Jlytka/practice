
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

class Digit {
public:
    Digit(const string& inputFile, const string& outputFile, const string& logFile);

   
    bool isAllDigits(const string& str);
    void processFile();
    void printLog();

private:
    string inputFile;
    string outputFile;
    string logFile;
};

Digit::Digit(const string& inputFile, const string& outputFile, const string& logFile)
    : inputFile(inputFile), outputFile(outputFile), logFile(logFile) {}



bool Digit::isAllDigits(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void Digit::processFile() {
    ifstream inputFileStream(inputFile);
    ofstream outputFileStream(outputFile);
    ofstream logFileStream(logFile);

    string line;
    vector<int> numbers;

    while (getline(inputFileStream, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            if (isAllDigits(word)) {
                int number = stoi(word);
                numbers.push_back(number);
            }
        }
    }

    if (!numbers.empty()) {
        outputFileStream << "found digits:" << endl;
        for (int number : numbers) {
            outputFileStream << number << endl;
        }
        outputFileStream << "amount: " << numbers.size() << endl;
    } else {
        outputFileStream << "digits are not found" << endl;
    }

    logFileStream << setw(10) << "data processing stage:" << endl;
    logFileStream << setw(10) << "incoming data: ";

    inputFileStream.clear();
    inputFileStream.seekg(0);

    while (getline(inputFileStream, line)) {
        logFileStream << line << endl;
    }

    logFileStream << endl;
    logFileStream << "results:" << endl;
    logFileStream << "found digits:" << endl;

    for (int number : numbers) {
        logFileStream << setw(9) << number << endl;
    }

    logFileStream << "amount: " << numbers.size() << endl;

    inputFileStream.close();
    outputFileStream.close();
    logFileStream.close();

    cout << "processing is complete." << endl;
}

void Digit::printLog() {
    ifstream logFileStream(logFile);
    string line;

    while (getline(logFileStream, line)) {
        cout << line << endl;
    }

    logFileStream.close();
}


