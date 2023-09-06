#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CommunalService {
private:
    string payer;
    double cost;
    string service;

public:
    void setPayer(const string& newPayer) {
        payer = newPayer;
    }

    void setCost(double newCost) {
        cost = newCost;
    }

    void setService(const string& newService) {
        service = newService;
    }

    string getPayer() const {
        return payer;
    }

    double getCost() const {
        return cost;
    }

    string getService() const {
        return service;
    }
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
    string payer, serviceDesc;
    double cost;

    cout << "Enter the payer: ";
    cin.ignore();
    getline(cin, payer);
    service.setPayer(payer);

    cout << "Enter the cost: ";
    cin >> cost;
    service.setCost(cost);

    cout << "Enter the service: ";
    cin.ignore();
    getline(cin, serviceDesc);
    service.setService(serviceDesc);

    file << service.getPayer() << "," << service.getCost() << "," << service.getService() << endl;

    file.close();
    cout << "Information added to the database." << endl;
}

void printData(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening the database file." << endl;
        return;
    }

    vector<CommunalService> services;
    CommunalService service;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1 + 1);
        string payer = line.substr(0, pos1);
        double cost = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
        string serviceDesc = line.substr(pos2 + 1);

        service.setPayer(payer);
        service.setCost(cost);
        service.setService(serviceDesc);

        services.push_back(service);
    }

    file.close();

    // Сортування за іменем платника
    sort(services.begin(), services.end(), [](const CommunalService& a, const CommunalService& b) {
        return a.getPayer() < b.getPayer();
    });

    for (const auto& service : services) {
        cout << "Payer: " << service.getPayer() << endl;
        cout << "Cost: " << service.getCost() << endl;
        cout << "Service: " << service.getService() << endl;
        cout << "------------------------" << endl;
    }
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
        string payer = line.substr(0, pos1);
        double cost = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
        string serviceDesc = line.substr(pos2 + 1);

        service.setPayer(payer);
        service.setCost(cost);
        service.setService(serviceDesc);

        if (service.getPayer() == searchCriteria || service.getService() == searchCriteria) {
            cout << "Payer: " << service.getPayer() << endl;
            cout << "Cost: " << service.getCost() << endl;
            cout << "Service: " << service.getService() << endl;
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
