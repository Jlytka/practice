#include <iostream>
using namespace std;

template <typename T>

class Array {
private:
   
    T* data;
    int size;

public:

    Array(int size) {
        this->size = size;
        data = new double[size];
    }

    ~Array() {
        delete[] data;
    }

    T* getData(){
        return data;
    }
    int getSize() const {
        return size;
    }

    //template <typename T>
    void calculateProductOfEvenElements() {
        T product = 1;
        for (int i = 0; i < size; i += 2) {
            product *= data[i];
        }
        cout << "product of elements with even indices: " << product << endl;
    }

    //template <typename T>
    void calculateSumBetweenZeros() {
        int firstZeroIndex = size;
        int lastZeroIndex = 0;

        for (int i = 0; i < size; i++) {
            if (data[i] == 0) {
                firstZeroIndex = i;
                break;
            }
        }

        if (firstZeroIndex == size) {
            cout << "no zeros found in the array." << endl;
            return;
        }

        for (int i = firstZeroIndex + 1; i < size; i++) {
            if (data[i] == 0) {
                lastZeroIndex = i;
                break;
            }
        }

        if (lastZeroIndex == 0) {
            cout << "only one zero found in the array." << endl;
            return;
        }

        T sum = 0;
        for (int i = firstZeroIndex + 1; i < lastZeroIndex; i++) {
            sum += data[i];
        }

        cout << "sum of elements between the first and last zero: " << sum << endl;
    }

    //template <typename T>
    void sortPositiveFirst() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if ((data[j] < 0 && data[j + 1] >= 0) ) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
};