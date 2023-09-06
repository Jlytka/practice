
#include"matrix.h"
class minimal {
public:
    static int doSomething(const Matrix& matrix) {
        int minElement = matrix.data[0][0];
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                if (matrix.data[i][j] < minElement) {
                    minElement = matrix.data[i][j];
                }
            }
        }
        return minElement;
    }
};

