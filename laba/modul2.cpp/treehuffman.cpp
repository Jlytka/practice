#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct CommunalService {
    string payer;
    double cost;
    string service;
};

void createDatabase(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error creating the database file." << endl;
        return;
    }
    file.close();
    cout << "Database created successfully." << endl;
}

void addData(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening the database file." << endl;
        return;
    }

    CommunalService service;
    cout << "Enter the payer: ";
    cin.ignore();
    getline(cin, service.payer);
    cout << "Enter the cost: ";
    cin >> service.cost;
    cout << "Enter the service: ";
    cin.ignore();
    getline(cin, service.service);

    file << service.payer << "," << service.cost << "," << service.service << endl;

    file.close();
    cout << "Information added to the database." << endl;
}

void printData(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening the database file." << endl;
        return;
    }

    CommunalService service;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        service.payer = line.substr(0, pos1);
        service.cost = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
        service.service = line.substr(pos2 + 1);

        cout << "Payer: " << service.payer << endl;
        cout << "Cost: " << service.cost << endl;
        cout << "Service: " << service.service << endl;
        cout << "------------------------" << endl;
    }

    file.close();
}

void searchData(const string& filename, const string& searchCriteria) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening the database file." << endl;
        return;
    }

    CommunalService service;
    string line;
    bool found = false;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        service.payer = line.substr(0, pos1);
        service.cost = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
        service.service = line.substr(pos2 + 1);

        if (service.payer == searchCriteria || service.service == searchCriteria) {
            cout << "Payer: " << service.payer << endl;
            cout << "Cost: " << service.cost << endl;
            cout << "Service: " << service.service << endl;
            cout << "------------------------" << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No information found for the specified criteria." << endl;

    file.close();
}

int main() {
    string filename;
    cout << "Enter the database filename: ";
    cin >> filename;

    int choice;
    do {
        cout << "1. Create database" << endl;
        cout << "2. Add data" << endl;
        cout << "3. Print data" << endl;
        cout << "4. Search data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createDatabase(filename);
                break;
            case 2:
                addData(filename);
                break;
            case 3:
                printData(filename);
                break;
            case 4: {
                string searchCriteria;
                cout << "Enter the search criteria: ";
                cin.ignore();
                getline(cin, searchCriteria);
                searchData(filename, searchCriteria);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
