#include "array.h"

template <class T>
class Matrix2: public Matrix<T>{
private:
    int minRow;
    int maxRow;
    int minColumn;
    int maxColumn;

public:
    Matrix2(int minR, int maxR, int minC, int maxC)
        : minRow(minR), maxRow(maxR), minColumn(minC), maxColumn(maxC){
        int numRows = maxRow - minRow + 1;
        int numColumns = maxColumn - minColumn + 1;
        this -> setRows(numRows);
        this -> setCol(numColumns);

        this -> setMat(new T *[numRows]);
        for (int i = 0; i < numRows; i++) {
            this->getMat()[i] = new T[numColumns];
        }
    }
};




