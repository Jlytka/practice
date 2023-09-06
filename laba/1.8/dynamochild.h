#include<iostream>
#include"dynamo.h"
using namespace std;
template<typename T>
class Arraysmall : public Array<T> {
private:
    int lower;  
    int upper;  
    T* data;
    int size;

public:
    Arraysmall(int lower, int upper) : size(upper - lower + 1), lower(lower), upper(upper) {
        this->data = new T[this->size];
    }
     void inputt() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i << ": ";
            cin >> data[i];
        }
    }
     void outputt() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

   
};
