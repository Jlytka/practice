#include <iostream>
#include "diggit.h"
using namespace std;

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    string logFile = "log.txt";

    Digit digit(inputFile, outputFile, logFile);
    digit.processFile();
    digit.printLog();

    return 0;
}
