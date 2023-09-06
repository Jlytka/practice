#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void input();
void nameinput();

int main() {
    input();
    nameinput(); 

    return 0;
}

void nameinput() {
    ofstream actionsFile("actions.txt"); 

    if (actionsFile.is_open()) {
        actionsFile << "opened 'text.txt' " << endl;

        ifstream inputFile("text.txt");
        if (inputFile.is_open()) {
            actionsFile << "opened 'result.txt'" << endl;
            ofstream outputFile("result.txt"); 

            if (outputFile.is_open()) {
                actionsFile << "start of searching words that starts on 'T'" << endl;

                string line;
                while (getline(inputFile, line)) {
                    istringstream iss(line);

                    string word;
                    while (iss >> word) {
                        if (!word.empty() && word[0] == 'T') {
                            outputFile << word << endl;
                            actionsFile << "founded word that starts on 'T': " << word << endl; 
                        }
                    }
                }

                actionsFile << "end of searching words that starts on 'T'" << endl;

                outputFile.close(); 
                actionsFile << "closed file 'result.txt'" << endl;
            } else {
                actionsFile << "unable to open file 'result.txt' " << endl;
            }

            inputFile.close(); 
            actionsFile << "closed file 'text.txt' " << endl;
        } else {
            actionsFile << "unable to open file  'text.txt' " << endl;
        }

        actionsFile.close(); 
    } else {
        cout << "unable to open actions.txt.";
    }
}



void input() {
    ofstream outputFile;
    outputFile.open("text.txt"); 

    if (outputFile.is_open()) {
        string input;
        while (true) {
            cout << "enter names or stop to fifnish program: ";
            getline(cin, input);
            
            if (input == "stop") {  
                break; 
            }
            
            outputFile << input << endl; 
        }
        
        outputFile.close(); 
    } else {
        cout << "unable to open file";
    }
}
            