#include <iostream>
#include <ctime>

using namespace std;

template <typename T>

class Matrix{
private:
    T **mat;
    int rows;
    int columns;

public:
    T **getMat(){
        return mat;
    }

    Matrix &setMat(T** arr){
        mat=arr;
        return *this;
    }

    int getRows(){
        return rows;
    }

    Matrix &setRows(int rows_){
        rows = rows_;
        return *this;
    }

    int getColumns(){
        return columns;
    }

    Matrix &setCol(int col){
        columns = col;
        return *this;
    }

    Matrix() : mat(nullptr), rows(0), columns(0) {}

    Matrix(int numRows, int numColumns) : rows(numRows), columns(numColumns){
        mat = new T *[rows];
        for (int i = 0; i < rows; i++){
            mat[i] = new T[columns];
        }
    }

    Matrix(const Matrix &other) : rows(other.rows), columns(other.columns){
        mat = new T *[rows];
        for (int i = 0; i < rows; i++){
            mat[i] = new T[columns];
            for (int j = 0; j < columns; j++){
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    ~Matrix(){
        for (int i = 0; i < rows; i++){
            delete[] mat[i];
        }
        delete[] mat;
    }

    void setElement(){
        if (rows == 0 || columns == 0){
            throw out_of_range("invalid matrix dimensions");
        }

        srand(time(nullptr));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                mat[i][j] = static_cast<T>(rand() % 50 * 0.2);
            }
        }
    }

    T getElement(int row, int column){
        if (row < 0 || row >= rows || column < 0 || column >= columns){
            throw out_of_range("invalid row or column index");
        }
        return mat[row][column];
    }

    void show(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool find(T value){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (mat[i][j] == value){
                    return true;
                }
            }
        }
        return false;
    }
};