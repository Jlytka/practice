
#ifndef matritra
#define matritra
#include <iostream>
#include"vector.h"

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(new int*[rows]) {
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    void fillMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> data[i][j];
            }
        }
    }
    friend void mutliply(const Matrix& a,vector& b );

    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    int get_rows(){
        return rows;
    }
    int get_colmn(){
        return cols;
    }
    
    friend class minimal;

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
};
#endif