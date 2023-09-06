#include <iostream>

using namespace std;

template<typename T>
class Array {
private:
    T* arr;
    int size;
public:
    Array() : arr(nullptr), size(0) {}

    Array(int size) : size(size) {
        arr = new T[size];
    }

    Array(const Array& other) : size(other.size) {
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    void output() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void search(T num) const {
        bool find = false;
        for (int i = 0; i < size; i++) {
            if (num == arr[i]) {
                cout << "There is a number at position " << i << endl;
                find = true;
                break;
            }
        }
        if (!find) {
            cout << "No number like that" << endl;
        }
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i << ": ";
            cin >> arr[i];
        }
    }
};
