#include <iostream> 
#include "Patient.h"

using namespace std; 

Complex qva(const Complex& z) { 
    double mod = sqrt(z.module); 
    double ang = z.angle / 2; 
    return Complex(mod, ang); 
}

Complex& operator--(Complex& z) {
        z.module--;
        return z;
    }
 
int main(){ 
    double m1, m2; 
    double a1, a2; 
    cout << "first number\nenter module 1 "; 
    cin >> m1; 
    cout << "enter angle 1 "; 
    cin >> a1; 
    cout << "second number\nenter module 2 "; 
    cin >> m2; 
    cout << "enter angle 2 "; 
    cin >> a2; 
    Complex z1(m1, a1); 
    Complex z2(m2, a2); 
     
    cout << z1 << " + " << z2 << " = " << z1 + z2 << endl; 
    cout << z1 << " - " << z2 << " = " << z1 - z2 << endl; 
    cout << z1 << " * " << z2 << " = " << z1 * z2 << endl; 
    cout << z1 << " / " << z2 << " = " << z1 / z2 << endl; 
    Complex pow1 = z1 ^ 2; 
    cout << z1 << " ^ 2 = " << pow1 << endl; 
    Complex pow2 = z2 ^ 2;
    cout << z2 << " ^ 2 = " << pow2<< endl; 
    cout << "sqrt(" << z1 << ") = " << qva(z1) << endl;   
    cout << "sqrt(" << z2 << ") = " << qva(z2) << endl;
    cout << z1 << "++ = " << ++z1 << endl;
    cout << z2 << "-- = " << --z2 << endl;
 
}
