#include <iostream>
#include <fstream>
#include <string>
#include "file.h"

using namespace std;


int main() {
    Fille obj;
    int choice;

    do {
        cout << "menu:" << endl;
        cout << "1. enter data from keyboard" << endl;
        cout << "2. add new data" << endl;
        cout << "3. edit data in file" << endl;
        cout << "4. take a look on data" << endl;
        cout << "5. edit for exercise" << endl;
        cout << "0. exit" << endl;
        cout << "choose option ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.fillFile();
                break;
            case 2:
                obj.fillFile();
                break;
            case 3:
                obj.editFile();
                break;
            case 4:
                obj.viewFile();
                break;
            case 5:
                obj.performTask();
                break;
            case 0:
                cout << "Bye" << endl;
                break;
            default:
                cout << "..." << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
