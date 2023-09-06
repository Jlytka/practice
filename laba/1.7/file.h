#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fille{

public:
    void fillFile() {
        ofstream file("data.txt", ios::app); 
        if (!file) {
            cout << "error" << endl;
            return;
        }

        string name, surname;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter surname: ";
        cin >> surname;

        file << name << " " << surname << endl; 
        file.close(); 
    }

    void editFile() {
        ifstream file("data.txt");
        if (!file) {
            cout << "error" << endl;
            return;
        }

        string nameToEdit, newName, newSurname;
        cout << "enter surname you want to edit ";
        cin >> nameToEdit;

        
        ofstream tempFile("temp.txt");
        if (!tempFile) {
            cout << "error" << endl;
            return;
        }

        string name, surname;
        bool found = false;
        while (file >> name >> surname) {
            if (surname == nameToEdit) {
                cout << "Enter new name";
                cin >> newName;
                cout << "Enter new surname ";
                cin >> newSurname;

                tempFile << newName << " " << newSurname << endl;
                found = true;
            } else {
                tempFile << name << " " << surname << endl;
            }
        }

        file.close();
        tempFile.close();

        
        remove("data.txt");
        rename("temp.txt", "data.txt");

        if (found) {
            cout << "succesfulyy edited" << endl;
        } else {
            cout << "didn't found '" << nameToEdit  << endl;
        }
    }
    void viewFile() {
        ifstream file("data.txt");
        if (!file) {
            cout << "error" << endl;
            return;
        }

        string name, surname;
        cout << "Data in file: " << endl;
        while (file >> name >> surname) {
            cout << name << " " << surname << endl;
        }

        file.close();
    }
    void performTask() {
        ifstream inputFile("data.txt");
        if (!inputFile) {
            cout << "error" << endl;
            return;
        }

        ofstream outputFile("names.txt", ios::app);
        if (!outputFile) {
            cout << "error" << endl;
            inputFile.close();
            return;
        }

        string name, surname;
        cout << "surnames are added to file:" << endl;
        while (inputFile >> name >> surname) {
            if (surname[0] == 'T') {
                cout << surname << endl;
                outputFile << surname << endl;
            }
        }

        inputFile.close();
        outputFile.close();
    }

};