#include <iostream>
#include "masyv.h";
using namespace std;

int main() {
    int N;
    cout << "enter the size of the array: ";
    cin >> N;

    Array<double> array(N);

    cout << "enter the elements of the array:" << endl;
    for (size_t i = 0; i < N; i++) {
        cin >> array.getData()[i];
    }
    
    array.calculateProductOfEvenElements();
    array.calculateSumBetweenZeros();
    array.sortPositiveFirst();

    cout << "sorted array: ";
    for (size_t i = 0; i < N; i++) {
        cout << array.getData()[i] << " ";
    }
    cout << endl;

    return 0;
}
