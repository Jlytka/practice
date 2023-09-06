#include <iostream>
#include "boks.h"

using namespace std;

int main() {
    double a, b, c;

    cout << "enter three numbers for box" << endl;
    if (!(cin >> a >> b >> c)) {
        cout << "do you know what does numbers mean?" << endl;
        exit(1);
    }

    try {
    Box box(a, b, c);
    } 
    catch(const char* errorMsg) {
        cout << errorMsg<< endl;
        exit(1);
    }
    return 0;
}