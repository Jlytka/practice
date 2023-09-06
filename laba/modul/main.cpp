#include <iostream>
#include "Drib.h";

Drib& operator--(Drib& p){
    p.numerator--;
    return p;
}
int main() {
    
    Drib r1(2, 3);
    Drib r2(3, 4);
    Drib r3(2, 4);

    

    cout << "r1 + r2 = " << r1 + r2 << endl;
    cout << "r1 - r2 = " << r1 - r2 << endl;
    cout << "r1 == r2: " << (r1 == r2) << endl;
    cout << "r1 != r2: " << (r1 != r2) << endl;
   

   
    cout << "r1-- = " << --r1 << endl;

    return 0;
}