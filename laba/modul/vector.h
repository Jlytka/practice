#ifndef vectorss
#define vectorss
#include<iostream>

using namespace std;

class vector{
private:
    int rows;
    int colms;
    int **dataa;
public:
    
    vector(int r, int c): rows(r), colms(c),dataa(new int*[rows]) {
        for (int i = 0; i < rows; i++) {
            dataa[i] = new int[colms];
        }
    } 
    friend void mutliply(Matrix& a, vector& b);
    
    void fillVector() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> dataa[i][j];
            }
        }
    }
    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                cout << dataa[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~vector() {
        for (int i = 0; i < rows; i++) {
            delete[] dataa[i];
        }
        delete[] dataa;
    }
};
#endif
