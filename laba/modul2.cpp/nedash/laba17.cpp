#include<iostream>
#include<cmath>
#include<algorithm>
#include "func.h"

using namespace std;



int main() {
    Func func;

    int size;
    cin >> size;

    int* masyv = new int[size];
    
    for (int i = 0; i < size; i++) {
        cout << "enter element" << endl;
        cin >> masyv[i];
    }
    int min = func.findMinElement(masyv, size);
    cout << "minimal element is " << min << endl;

 

    cout << "suma between - elements = " << func.suma(masyv, size) << endl;

    func.sortArrayByAbsoluteValue(masyv, size);

    cout << "sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << masyv[i] << " ";
    }
    cout << endl;

    delete[] masyv;

    return 0;
}
