#include<iostream>

#include"matrix.h"
#include"vector.h"
#include"min.h"
using namespace std;

int main(){
    int r, c, r_1, c_1;
    cin >> r >> c >> r_1 >> c_1;
    Matrix matrixx(r, c);
    matrixx.fillMatrix();
    vector vectorr(r_1, c_1);
    vectorr.fillVector();
    minimal min_el;
    cout << "min el = " << min_el.doSomething(matrixx);
    for (int i = 0; i < r){
        for( int j = 0; j < c; j++){
            for (int k = 0; k < r_1; k++){
                
            }
        }
    }
        
    

    


}