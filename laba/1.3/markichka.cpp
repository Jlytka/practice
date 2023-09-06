#include <iostream> 
#include "Compleks.h"

using namespace std; 



Complex& operator--(Complex& n) {
        n.module--;
        return n;
    }
Complex root(const Complex& n) { 
    double mod = sqrt(n.module); 
    double ang = n.angle / 2; 
    return Complex(mod, ang); 
}
 
int main(){ 
    double module_1, module_2; 
    double angle_1, angle_2; 
    cout << "Enter module of first complex number "; 
    cin >> module_1; 
    cout << "enter angle of first complex number"; 
    cin >> angle_1; 
    cout << "Now you will work with second complex number "<< endl; 
    cout << "Enter module of the second complex number";
    cin >> module_2; 
    cout << "enter angle of the second complex number "; 
    cin >> angle_2; 
    Complex n1(module_1, angle_1); 
    Complex n2(module_2, angle_2); 
     
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl; 
    cout << n1 << " - " << n2 << " = " << n1 - n2 << endl; 
    cout << n1 << " * " << n2 << " = " << n1 * n2 << endl; 
    cout << n1 << " / " << n2 << " = " << n1 / n2 << endl; 
    cout << n1 << "++ = " << ++n1 << endl;
    cout << n2 << "-- = " << --n2 << endl;
    Complex pow1 = n1 ^ 2; 
    cout << n1 << " ^ 2 = " << pow1 << endl; 
    Complex pow2 = n2 ^ 2;
    cout << n2 << " ^ 2 = " << pow2<< endl; 
    cout << "square root of (" << n1 << ") = " << root(n1) << endl;   
    cout << "square root of (" << n2 << ") = " << root(n2) << endl;
    
 
}
