#include<iostream>
#include <fstream>
#include <string>
#include <vector>

class WordProcessor {
public:
    WordProcessor();

    bool OpenFiles();
    void CloseFiles();
    void ProcessData();
    void WriteOutput();
    void WriteProtocol();

private:
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::ofstream logFile;
    std::vector<std::string> words;
    std::vector<int> wordLengths;

    void CountWordLengths(const std::string& word);
    void ProcessLine(const std::string& line);
};

WordProcessor::WordProcessor() : wordLengths(11, 0) {}

bool WordProcessor::OpenFiles() {
    inputFile.open("inp.txt");
    outputFile.open("out.txt");
    logFile.open("prot.txt");

    if (!inputFile.is_open()) {
        std::cout << "Помилка відкриття вхідного файлу." << std::endl;
        return false;
    }

    if (!outputFile.is_open()) {
        std::cout << "Помилка відкриття вихідного файлу." << std::endl;
        return false;
    }

    if (!logFile.is_open()) {
        std::cout << "Помилка відкриття файлу протоколу." << std::endl;
        return false;
    }

    return true;
}

void WordProcessor::CloseFiles() {
    inputFile.close();
    outputFile.close();
    logFile.close();
}

void WordProcessor::CountWordLengths(const std::string& word) {
    int length = word.length();
    if (length <= 10) {
        ++wordLengths[length];
    } else {
        ++wordLengths[10];
    }
}

void WordProcessor::ProcessLine(const std::string& line) {
    std::string word;
    for (char c : line) {
        if (std::isalnum(c)) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            CountWordLengths(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        words.push_back(word);
        CountWordLengths(word);
    }
}

void WordProcessor::ProcessData() {
    std::string line;
    while (std::getline(inputFile, line)) {
        ProcessLine(line);
    }
}

void WordProcessor::WriteOutput() {
    for (int i = 1; i <= 10; ++i) {
        outputFile << "Слова довжини " << i << " символ(ів):" << std::endl;
        for (const std::string& word : words) {
            if (word.length() == i) {
                outputFile << word << std::endl;
            }
        }
        outputFile << std::endl;
    }
}

void WordProcessor::WriteProtocol() {
    logFile << "Етап обробки даних:" << std::endl;
    logFile << "Вхідні дані:" << std::endl;

    std::ifstream inputFile2("inp.txt");
    if (inputFile2.is_open()) {
        std::string fileContents((std::istreambuf_iterator<char>(inputFile2)),
                                 std::istreambuf_iterator<char>());
        logFile << fileContents << std::endl;
        inputFile2.close();
    } else {
        logFile << "Помилка відкриття вхідного файлу для протоколу." << std::endl;
    }

    logFile << "Результати обробки даних:" << std::endl;

    for (int i = 1; i <= 10; ++i) {
        logFile << "Слова довжини " << i << " символ(ів):" << std::endl;
        for (const std::string& word : words) {
            if (word.length() == i) {
                logFile << word << std::endl;
            }
        }
        logFile << std::endl;
    }
}


